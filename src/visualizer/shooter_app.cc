#include "visualizer/shooter_app.h"

shooter::visualizer::ShooterApp::ShooterApp()
    : player_(glm::vec2(getDisplay()->getWidth() / 2,
                        getDisplay()->getHeight() / 2),
              kPlayerMovementSpeed) {
  ci::app::setWindowSize(getDisplay()->getWidth(), getDisplay()->getHeight());
}

void shooter::visualizer::ShooterApp::setup() {
  player_sprite_ =
      ci::gl ::Texture::create(loadImage(loadResource("player2.png")));
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
  ci::Color8u background_color(0, 66, 37);  // racing green
  ci::gl::clear(background_color);

  // draw player sprites
  ci::gl::color(ci::Color("white"));
  ci::gl::draw(
      player_sprite_,
      glm::vec2((player_.GetPosition().x - player_sprite_->getWidth() / 2),
                (player_.GetPosition().y - player_sprite_->getHeight() / 2 -
                 player_sprite_->getHeight() / 30)));

  player_.Draw();

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
