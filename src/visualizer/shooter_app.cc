#include "visualizer/shooter_app.h"

#include <cmath>

shooter::visualizer::ShooterApp::ShooterApp()
    : player_(glm::vec2(getDisplay()->getWidth() / 2,
                        getDisplay()->getHeight() / 2),
              kPlayerMovementSpeed) {
  ci::app::setWindowSize(getDisplay()->getWidth(), getDisplay()->getHeight());
}

void shooter::visualizer::ShooterApp::setup() {
  player_sprite_ =
      ci::gl ::Texture::create(loadImage(loadResource("spaceship2.png")));
  alien_sprite_ =
      ci::gl::Texture::create(loadImage(loadResource("alien1.png")));
}

void shooter::visualizer::ShooterApp::update() {
  size_t i = 0;
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

  DrawPlayer();

  for (Bullet &bullet : projectiles_) {
    bullet.Draw();
  }
}

void shooter::visualizer::ShooterApp::keyDown(ci::app::KeyEvent event) {
  held_keys_.insert(event.getCode());
}

void shooter::visualizer::ShooterApp::keyUp(ci::app::KeyEvent event) {
  held_keys_.erase(event.getCode());
}

void shooter::visualizer::ShooterApp::mouseDown(ci::app::MouseEvent event) {
  projectiles_.push_back(player_.ShootBullet(event.getPos()));
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

// Code derived from:
// https://forum.libcinder.org/topic/a-few-missing-methods-in-cinder
float shooter::visualizer::ShooterApp::AngleBetween(const glm::vec2 &a,
                                                    const glm::vec2 &b) {
  return -1.0f * std::atan2(a.x * b.y - a.y * b.x, a.x * b.x + a.y * b.y);
}
