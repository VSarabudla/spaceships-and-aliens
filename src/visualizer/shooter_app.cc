#include "visualizer/shooter_app.h"

#include <cmath>

shooter::visualizer::ShooterApp::ShooterApp() {
  ci::app::setWindowSize(getDisplay()->getWidth(), getDisplay()->getHeight());
}

void shooter::visualizer::ShooterApp::setup() {
  hud_font_ = ci::Font("URW Gothic", getWindowHeight() / 5);
  score_ = 0;

  // load sprites
  player_sprite_ = ci::gl ::Texture::create(
      loadImage(loadResource("assets/spaceship2.png")));
  alien_sprite_ =
      ci::gl::Texture::create(loadImage(loadResource("assets/alien1.png")));

  // load player shooting sound
  ci::audio::SourceFileRef source_file =
      ci::audio::load(loadResource("assets/player_shooting_sound.mp3"));
  player_shooting_sound_ = ci::audio::Voice::create(source_file);

  // initialize player
  player_ = Player(
      glm::vec2(getDisplay()->getWidth() / 2, getDisplay()->getHeight() / 2),
      player_sprite_->getWidth() / 2, kPlayerMovementSpeed, kPlayerHealthPoints,
      kPlayerBulletColor);

  // use time to seed random number generator
  srand(static_cast<int>(std::time(nullptr)));

  // initialize event timer
  event_timer_ = ci::Timer(true);
}

void shooter::visualizer::ShooterApp::update() {
  // handle bullet collisions with player & aliens
  player_.HandleCollisions(&projectiles_, kAlienBulletColor);

  size_t i = 0;
  for (Alien &alien : aliens_) {
    alien.HandleCollisions(&projectiles_, kPlayerBulletColor);

    if (alien.GetHealthPoints() <= 0) {
      aliens_.erase(aliens_.begin() + i);
      score_++;
      continue;
    }
    i++;
    alien.MoveTowardsPlayer(player_.GetPosition());
  }

  // remove bullets outside of application window
  i = 0;
  for (Bullet &bullet : projectiles_) {
    if (bullet.GetPosition().x < 0 || bullet.GetPosition().y < 0 ||
        bullet.GetPosition().x > getWindowWidth() ||
        bullet.GetPosition().y > getWindowHeight()) {
      projectiles_.erase(projectiles_.begin() + i);
      continue;
    }
    bullet.UpdatePosition();
    i++;
  }

  // spawn aliens periodically that shoot at player
  if (event_timer_.getSeconds() > kAlienSpawnRate) {
    aliens_.emplace_back(
        glm::vec2(rand() % getWindowWidth(), rand() % getWindowHeight()),
        alien_sprite_->getWidth() / 2, kAlienMovementSpeed, kAlienHealthPoints,
        kAlienBulletColor, kAlienBulletMovementSpeed);
    for (Alien &alien : aliens_) {
      projectiles_.push_back(alien.ShootBullet(player_.GetPosition()));
    }
    event_timer_.start();
  }

  for (int held_key : held_keys_) {
    switch (held_key) {
      case ci::app::KeyEvent::KEY_w:
        player_.MoveUp();
        break;
      case ci::app::KeyEvent::KEY_a:
        player_.MoveLeft();
        break;
      case ci::app::KeyEvent::KEY_s:
        player_.MoveDown();
        break;
      case ci::app::KeyEvent::KEY_d:
        player_.MoveRight();
        break;
    }
  }
}

void shooter::visualizer::ShooterApp::draw() {
  ci::Color8u background_color(0, 0, 0);  // black
  ci::gl::clear(background_color);

  // draw "Game Over" splash screen
  if (player_.GetHealthPoints() <= 0) {
    ci::gl::drawStringCentered(
        "Game Over", glm::vec2(getWindowWidth() / 2, getWindowHeight() / 2),
        ci::Color("red"), ci::Font("Inconsolata", getWindowWidth() / 6));
    return;
  }

  DrawPlayer();

  for (const Alien &alien : aliens_) {
    DrawAlien(alien);
  }

  for (Bullet &bullet : projectiles_) {
    bullet.Draw();
  }

  DrawHUD();
}

void shooter::visualizer::ShooterApp::keyDown(ci::app::KeyEvent event) {
  held_keys_.insert(event.getCode());
}

void shooter::visualizer::ShooterApp::keyUp(ci::app::KeyEvent event) {
  held_keys_.erase(event.getCode());
}

void shooter::visualizer::ShooterApp::mouseDown(ci::app::MouseEvent event) {
  player_shooting_sound_->stop();
  projectiles_.push_back(player_.ShootBullet(event.getPos()));
  player_shooting_sound_->start();
}

void shooter::visualizer::ShooterApp::DrawPlayer() {
  ci::gl::pushModelMatrix();
  ci::gl::translate(player_.GetPosition().x, player_.GetPosition().y);
  ci::gl::rotate(-AngleBetween(
      glm::normalize(glm::vec2(0, 1)),
      glm::normalize(glm::vec2(getMousePos()) - player_.GetPosition())));

  // draw player sprite in transformed matrix
  ci::gl::color(ci::Color("white"));
  ci::gl::draw(player_sprite_, glm::vec2((-player_sprite_->getWidth() / 2),
                                         (-player_sprite_->getHeight() / 2 -
                                          player_sprite_->getHeight() / 25)));
  ci::gl::popModelMatrix();
}

void shooter::visualizer::ShooterApp::DrawAlien(const shooter::Alien &alien) {
  ci::gl::pushModelMatrix();
  ci::gl::translate(alien.GetPosition().x, alien.GetPosition().y);
  ci::gl::rotate(-AngleBetween(
      glm::normalize(glm::vec2(0, 1)),
      glm::normalize(player_.GetPosition() - alien.GetPosition())));

  // draw alien sprite in transformed matrix
  ci::gl::color(ci::Color("white"));
  ci::gl::draw(alien_sprite_, glm::vec2((-alien_sprite_->getWidth() / 2),
                                        (-alien_sprite_->getHeight() / 2)));
  ci::gl::popModelMatrix();
}

void shooter::visualizer::ShooterApp::DrawHUD() {
  // display player HP
  ci::gl::drawString(
      "HP: " + std::to_string(player_.GetHealthPoints()),
      glm::vec2(hud_font_.getSize(), getWindowHeight() - hud_font_.getSize()),
      ci::Color("white"), hud_font_);

  // display current score
  ci::gl::drawStringCentered(
      "Score: " + std::to_string(score_),
      glm::vec2(getWindowWidth() / 2, getWindowHeight() - hud_font_.getSize()),
      ci::Color("white"), hud_font_);

  // display frames per second
  ci::gl::drawStringRight("FPS: " + std::to_string(getAverageFps()),
                          glm::vec2(getWindowWidth() - hud_font_.getSize(),
                                    getWindowHeight() - hud_font_.getSize()),
                          ci::Color("white"), hud_font_);
}

// Code derived from:
// https://forum.libcinder.org/topic/a-few-missing-methods-in-cinder
float shooter::visualizer::ShooterApp::AngleBetween(const glm::vec2 &a,
                                                    const glm::vec2 &b) {
  return -1.0f * std::atan2(a.x * b.y - a.y * b.x, a.x * b.x + a.y * b.y);
}
