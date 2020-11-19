#ifndef FINAL_PROJECT_PLAYER_H
#define FINAL_PROJECT_PLAYER_H

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "core/bullet.h"

namespace shooter {

/**
 * Represents a user-controllable player
 */
class Player {
 public:
  /**
   * Creates a Player object
   *
   * @param position - position of player
   * @param movement_speed - movement speed of player when using WASD controls
   */
  Player(const glm::vec2 &position, float movement_speed);

  /**
   * Updates Player position based on what key is pressed by the user
   *
   * @param event - KeyEvent with information about what key is pressed
   */
  void UpdatePosition(const ci::app::KeyEvent &event);

  /**
   * Draws the player in the Cinder application
   */
  void Draw() const;

  /**
   * Returns a Bullet object traveling in the direction where the user clicks in
   * the application window
   *
   * @param mouse_position
   * @return
   */
  Bullet ShootBullet(const ci::ivec2 &mouse_position);

  glm::vec2 GetPosition() const;

 private:
  glm::vec2 position_;
  float movement_speed_;
};

}  // namespace shooter

#endif  // FINAL_PROJECT_PLAYER_H
