#include "core/player.h"

Player::Player(const glm::vec2 &position, float movement_speed)
    : position_(position), movement_speed_(movement_speed) {
}

void Player::UpdatePosition(const ci::app::KeyEvent &event) {
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

void Player::Draw() const {
  ci::gl::drawSolidCircle(position_, 10);
}
