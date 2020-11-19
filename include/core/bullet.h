#ifndef FINAL_PROJECT_BULLET_H
#define FINAL_PROJECT_BULLET_H

#include "cinder/gl/gl.h"

namespace shooter {

class Bullet {
 public:
  Bullet(const glm::vec2 &position, const glm::vec2 &velocity, float radius);

  void Draw() const;

  void UpdatePosition();

  glm::vec2 GetVelocity() const;

  glm::vec2 GetPosition() const;

 private:
  glm::vec2 position_;
  glm::vec2 velocity_;
  float radius_;
};

} // namespace shooter

#endif //FINAL_PROJECT_BULLET_H
