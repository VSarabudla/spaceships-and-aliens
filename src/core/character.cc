#include "core/character.h"

shooter::Character::Character(const glm::vec2& position, float radius,
                              float movement_speed, int health_points)
    : position_(position),
      radius_(radius),
      movement_speed_(movement_speed),
      health_points_(health_points) {
}

void shooter::Character::MoveUp() {
  position_ += glm::vec2(0, -movement_speed_);
}

void shooter::Character::MoveDown() {
  position_ += glm::vec2(0, movement_speed_);
}

void shooter::Character::MoveLeft() {
  position_ += glm::vec2(-movement_speed_, 0);
}

void shooter::Character::MoveRight() {
  position_ += glm::vec2(movement_speed_, 0);
}

void shooter::Character::HandleCollisions(std::vector<Bullet>* bullets,
                                          const ci::Color& bullet_color) {
  size_t i = 0;

  // check for bullets that have hit player
  for (Bullet& bullet : *bullets) {
    if (glm::distance(position_, bullet.GetPosition()) <=
            radius_ + bullet.GetRadius() &&
        bullet.GetColor() == bullet_color) {
      bullets->erase(bullets->begin() + i);
      DecrementHealth();
      continue;
    }
    i++;
  }
}

int shooter::Character::GetHealthPoints() const {
  return health_points_;
}

void shooter::Character::DecrementHealth() {
  health_points_--;
}

glm::vec2 shooter::Character::GetPosition() const& {
  return position_;
}
