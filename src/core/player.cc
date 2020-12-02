#include "core/player.h"

shooter::Player::Player(const glm::vec2& position, float radius,
                        float movement_speed, int health_points,
                        ci::Color bullet_color)
    : position_(position),
      radius_(radius),
      movement_speed_(movement_speed),
      health_points_(health_points),
      bullet_color_(bullet_color) {
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

shooter::Bullet shooter::Player::ShootBullet(const ci::ivec2& mouse_position) {
  return shooter::Bullet(
      position_,
      2 * movement_speed_ *
          glm::normalize(glm::vec2(mouse_position.x - position_.x,
                                   mouse_position.y - position_.y)),
      movement_speed_ / 2, bullet_color_);
}

void shooter::Player::HandleCollisions(std::vector<Bullet>* bullets,
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

int shooter::Player::GetHealthPoints() const {
  return health_points_;
}

void shooter::Player::DecrementHealth() {
  health_points_--;
}

glm::vec2 shooter::Player::GetPosition() const& {
  return position_;
}
