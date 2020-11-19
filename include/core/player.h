#ifndef FINAL_PROJECT_PLAYER_H
#define FINAL_PROJECT_PLAYER_H

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "core/bullet.h"

namespace shooter {

class Player {
 public:
  Player(const glm::vec2 &position, float movement_speed);

  void UpdatePosition(const ci::app::KeyEvent &event);

  void Draw() const;

  Bullet ShootBullet(const ci::ivec2& mouse_position);
 private:
  glm::vec2 position_;
  float movement_speed_;
};

} // namespace shooter

#endif //FINAL_PROJECT_PLAYER_H
