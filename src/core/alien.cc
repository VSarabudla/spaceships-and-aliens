#include "core/alien.h"

shooter::Alien::Alien(const glm::vec2 &position, float movement_speed)
    : position_(position), movement_speed_(movement_speed) {
}

shooter::Bullet shooter::Alien::ShootBullet(const glm::vec2 &player_position) {
  return shooter::Bullet(
      position_, movement_speed_ * glm::normalize(player_position - position_),
      movement_speed_, ci::Color("green"));
}

glm::vec2 shooter::Alien::GetPosition() const & {
  return position_;
}

void shooter::Alien::MoveUp() {
  position_ += glm::vec2(0, -movement_speed_);
}

void shooter::Alien::MoveDown() {
  position_ += glm::vec2(0, movement_speed_);
}

void shooter::Alien::MoveLeft() {
  position_ += glm::vec2(-movement_speed_, 0);
}

void shooter::Alien::MoveRight() {
  position_ += glm::vec2(movement_speed_, 0);
}
