#ifndef FINAL_PROJECT_PLAYER_H
#define FINAL_PROJECT_PLAYER_H

#include "core/character.h"

namespace shooter {

/**
 * Represents a user-controllable player
 */
class Player : public Character {
 public:
  Player() = default;

  /**
   * Creates a Player object
   *
   * @param position - position of player
   * @param radius - radius of player sprite
   * @param movement_speed - movement speed of player when using WASD controls
   * @param health_points - health points of player
   * @param bullet_color - color of the bullet the player shoots
   */
  Player(const glm::vec2& position, float radius, float movement_speed,
         int health_points, ci::Color bullet_color);

  /**
   * Returns a Bullet object traveling in the direction where the user clicks in
   * the application window
   *
   * @param mouse_position
   * @return Bullet traveling in the direction where the user clicks
   */
  Bullet ShootBullet(const ci::ivec2& mouse_position);

 private:
  ci::Color bullet_color_;
};

}  // namespace shooter

#endif  // FINAL_PROJECT_PLAYER_H
