#include "core/bullet.h"

shooter::Bullet::Bullet(const glm::vec2 &position, const glm::vec2 &velocity,
                        float radius, const ci::Color &color)
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

ci::Color shooter::Bullet::GetColor() const {
  return color_;
}

float shooter::Bullet::GetRadius() const {
  return radius_;
}
