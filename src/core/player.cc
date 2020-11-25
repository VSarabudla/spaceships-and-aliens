#include "core/player.h"

shooter::Player::Player(const glm::vec2 &position, float movement_speed)
    : position_(position), movement_speed_(movement_speed) {
}

void shooter::Player::Draw() const {
  ci::gl::color(ci::Color("green"));
  ci::gl::drawSolidCircle(position_, movement_speed_);
}

shooter::Bullet shooter::Player::ShootBullet(const ci::ivec2 &mouse_position) {
  return shooter::Bullet(position_,
                         movement_speed_ * glm::normalize(glm::vec2(
                                               mouse_position.x - position_.x,
                                               mouse_position.y - position_.y)),
                         movement_speed_);
}

glm::vec2 shooter::Player::GetPosition() const {
  return position_;
}

void shooter::Player::MoveUp() {
  position_ += glm::vec2(0, -movement_speed_);
}

void shooter::Player::MoveDown() {
  position_ += glm::vec2(0, movement_speed_);
}

void shooter::Player::MoveLeft() {
  position_ += glm::vec2(-movement_speed_, 0);
}

void shooter::Player::MoveRight() {
  position_ += glm::vec2(movement_speed_, 0);
}
