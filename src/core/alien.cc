#include "core/alien.h"

shooter::Alien::Alien(const glm::vec2& position, float radius,
                      float movement_speed, int health_points,
                      ci::Color bullet_color)
    : position_(position),
      radius_(radius),
      movement_speed_(movement_speed),
      health_points_(health_points),
      bullet_color_(bullet_color) {
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

shooter::Bullet shooter::Alien::ShootBullet(const glm::vec2& player_position) {
  return shooter::Bullet(
      position_, movement_speed_ * glm::normalize(player_position - position_),
      movement_speed_, bullet_color_);
}

void shooter::Alien::HandleCollisions(std::vector<Bullet>* bullets,
                                      const ci::Color& bullet_color) {
  size_t i = 0;

  // check for bullets that have hit alien
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

int shooter::Alien::GetHealthPoints() const {
  return health_points_;
}

void shooter::Alien::DecrementHealth() {
  health_points_--;
}

glm::vec2 shooter::Alien::GetPosition() const& {
  return position_;
}
