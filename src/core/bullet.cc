#include "core/bullet.h"

shooter::Bullet::Bullet(const glm::vec2 &position, const glm::vec2 &velocity,
                        float radius, ci::Color color)
    : position_(position), velocity_(velocity), radius_(radius), color_(color) {
}

void shooter::Bullet::Draw() const {
  ci::gl::color(color_);
  ci::gl::drawSolidCircle(position_, radius_);
}

void shooter::Bullet::UpdatePosition() {
  position_ += velocity_;
}

glm::vec2 shooter::Bullet::GetVelocity() const {
  return velocity_;
}

glm::vec2 shooter::Bullet::GetPosition() const {
  return position_;
}
