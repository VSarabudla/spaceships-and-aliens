#ifndef FINAL_PROJECT_BULLET_H
#define FINAL_PROJECT_BULLET_H

#include "cinder/gl/gl.h"

namespace shooter {

/**
 * Represents a shot bullet
 */
class Bullet {
 public:
  /**
   * Creates a Bullet object
   *
   * @param position - position of bullet
   * @param velocity - velocity of bullet
   * @param radius - radius of bullet
   * @param color - color of bullet
   */
  Bullet(const glm::vec2 &position, const glm::vec2 &velocity, float radius,
         ci::Color color);

  /**
   * Draws the bullet in the Cinder application
   */
  void Draw() const;

  /**
   * Updates the location of the bullet based on position and velocity
   */
  void UpdatePosition();

  glm::vec2 GetVelocity() const;

  glm::vec2 GetPosition() const;

  ci::Color GetColor() const;

  float GetRadius() const;

 private:
  glm::vec2 position_;
  glm::vec2 velocity_;
  float radius_;
  ci::Color color_;
};

}  // namespace shooter

#endif  // FINAL_PROJECT_BULLET_H
