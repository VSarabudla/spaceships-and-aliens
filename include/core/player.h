#ifndef FINAL_PROJECT_PLAYER_H
#define FINAL_PROJECT_PLAYER_H

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

class Player {
 public:
  Player(const glm::vec2& position, float movement_speed);

  void UpdatePosition(const ci::app::KeyEvent& event);

  void Draw() const;

 private:
  glm::vec2 position_;
  float movement_speed_;
};

#endif //FINAL_PROJECT_PLAYER_H
