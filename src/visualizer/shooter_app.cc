#include "visualizer/shooter_app.h"

shooter::visualizer::ShooterApp::ShooterApp()
    : player_(glm::vec2(getDisplay()->getWidth() / 2,
                        getDisplay()->getHeight() / 2),
              kPlayerMovementSpeed) {
  ci::app::setWindowSize(getDisplay()->getWidth(), getDisplay()->getHeight());
}

void shooter::visualizer::ShooterApp::update() {
  for (Bullet &bullet : projectiles_) {
    bullet.UpdatePosition();
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
