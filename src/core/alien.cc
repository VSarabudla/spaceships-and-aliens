#include "core/alien.h"

shooter::Alien::Alien(const glm::vec2& position, float radius,
                      float movement_speed, int health_points,
                      const ci::Color& bullet_color,
                      float bullet_movement_speed)
    : Character(position, radius, movement_speed, health_points),
      bullet_color_(bullet_color),
      bullet_movement_speed_(bullet_movement_speed) {
}

shooter::Bullet shooter::Alien::ShootBullet(const glm::vec2& player_position) {
  return shooter::Bullet(
      position_,
      bullet_movement_speed_ * glm::normalize(player_position - position_),
      bullet_movement_speed_, bullet_color_);
}

void shooter::Alien::MoveTowardsPlayer(const glm::vec2& player_position) {
  if (player_position.x - position_.x > 0) {
    MoveRight();
  } else if (player_position.x - position_.x < 0) {
    MoveLeft();
  }
  if (player_position.y - position_.y > 0) {
    MoveDown();
  } else if (player_position.y - position_.y < 0) {
    MoveUp();
  }
}
