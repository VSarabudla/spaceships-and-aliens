#ifndef FINAL_PROJECT_ALIEN_H
#define FINAL_PROJECT_ALIEN_H

#include "core/character.h"

namespace shooter {

class Alien : public Character {
 public:
  /**
   * Creates an Alien object
   *
   * @param position - position of alien
   * @param radius - radius of alien sprite
   * @param movement_speed - movement speed of alien
   * @param health_points - health points of alien
   * @param bullet_color - color of the bullets the alien shoots
   */
  Alien(const glm::vec2& position, float radius, float movement_speed,
        int health_points, ci::Color bullet_color);

  /**
   * Returns a Bullet object traveling in the direction of the player in the
   * application window
   *
   * @param player_position - position of the player in the application window
   * @return
   */
  Bullet ShootBullet(const glm::vec2& player_position);

 private:
  ci::Color bullet_color_;
};

}  // namespace shooter

#endif  // FINAL_PROJECT_ALIEN_H
