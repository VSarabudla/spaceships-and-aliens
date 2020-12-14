#ifndef FINAL_PROJECT_ALIEN_H
#define FINAL_PROJECT_ALIEN_H

#include "core/character.h"

namespace shooter {

/**
 * Represents an alien enemy
 */
class Alien : public Character {
 public:
  /**
   * Creates an Alien object
   *
   * @param position - position of alien
   * @param radius - radius of alien sprite
   * @param movement_speed - movement speed of alien
   * @param health_points - health points of alien
   * @param bullet_color - color of bullets shot by alien
   * @param bullet_movement_speed - movement speed of bullets shot by alien
   */
  Alien(const glm::vec2& position, float radius, float movement_speed,
        int health_points, const ci::Color& bullet_color,
        float bullet_movement_speed);

  /**
   * Returns a Bullet object traveling in the direction of the player in the
   * application window
   *
   * @param player_position - position of the player in the application window
   * @return
   */
  Bullet ShootBullet(const glm::vec2& player_position);

  /**
   * Moves alien towards the player in the application
   *
   * @param player_position - position of the player in the application window
   */
  void MoveTowardsPlayer(const glm::vec2& player_position);

 private:
  ci::Color bullet_color_;
  float bullet_movement_speed_;
};

}  // namespace shooter

#endif  // FINAL_PROJECT_ALIEN_H
