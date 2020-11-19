#include "visualizer/shooter_app.h"

shooter::visualizer::ShooterApp::ShooterApp() : player_(glm::vec2(
    getDisplay()->getWidth() / 2, getDisplay()->getHeight() / 2),
                                                        kPlayerMovementSpeed) {
  ci::app::setWindowSize(getDisplay()->getWidth(),
                         getDisplay()->getHeight());
}

void shooter::visualizer::ShooterApp::update() {
  for (Bullet &bullet : projectiles_) {
    bullet.UpdatePosition();
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
  player_.UpdatePosition(event);
}

void shooter::visualizer::ShooterApp::mouseDown(ci::app::MouseEvent event) {
  projectiles_.push_back(player_.ShootBullet(event.getPos()));
}
