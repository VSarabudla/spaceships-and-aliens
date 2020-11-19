#include "core/bullet.h"

shooter::Bullet::Bullet(const glm::vec2 &position,
                        const glm::vec2 &velocity,
                        float radius)
    : position_(position), velocity_(velocity), radius_(radius) {
}

void shooter::Bullet::Draw() const {
  ci::gl::color(ci::Color("black"));
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
