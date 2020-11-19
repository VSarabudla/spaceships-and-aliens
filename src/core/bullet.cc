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
