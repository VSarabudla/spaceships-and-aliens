#include "core/player.h"

shooter::Player::Player(const glm::vec2& position, float radius,
                        float movement_speed, int health_points,
                        ci::Color bullet_color)
    : Character(position, radius, movement_speed, health_points),
      bullet_color_(bullet_color) {
}

shooter::Bullet shooter::Player::ShootBullet(const ci::ivec2& mouse_position) {
  return shooter::Bullet(
      position_,
      2 * movement_speed_ *
          glm::normalize(glm::vec2(mouse_position.x - position_.x,
                                   mouse_position.y - position_.y)),
      movement_speed_ / 2, bullet_color_);
}
