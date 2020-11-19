#include "core/player.h"

shooter::Player::Player(const glm::vec2 &position, float movement_speed)
    : position_(position), movement_speed_(movement_speed) {
}

void shooter::Player::UpdatePosition(const ci::app::KeyEvent &event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_w:
      position_ += glm::vec2(0, -movement_speed_);
      break;
    case ci::app::KeyEvent::KEY_a:
      position_ += glm::vec2(-movement_speed_, 0);
      break;
    case ci::app::KeyEvent::KEY_s:
      position_ += glm::vec2(0, movement_speed_);
      break;
    case ci::app::KeyEvent::KEY_d:
      position_ += glm::vec2(movement_speed_, 0);
      break;
  }
}

void shooter::Player::Draw() const {
  ci::gl::color(ci::Color("green"));
  ci::gl::drawSolidCircle(position_, movement_speed_);
}

shooter::Bullet shooter::Player::ShootBullet(const ci::ivec2 &mouse_position) {
  return shooter::Bullet(position_,
                         movement_speed_ * glm::normalize(glm::vec2(
                             mouse_position.x - position_.x,
                             mouse_position.y - position_.y)), movement_speed_);
}
