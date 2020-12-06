#include "core/alien.h"

shooter::Alien::Alien(const glm::vec2& position, float radius,
                      float movement_speed, int health_points,
                      ci::Color bullet_color)
    : Character(position, radius, movement_speed, health_points),
      bullet_color_(bullet_color) {
}

shooter::Bullet shooter::Alien::ShootBullet(const glm::vec2& player_position) {
  return shooter::Bullet(
      position_, movement_speed_ * glm::normalize(player_position - position_),
      movement_speed_, bullet_color_);
}
