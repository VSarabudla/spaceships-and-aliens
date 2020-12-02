#ifndef FINAL_PROJECT_ALIEN_H
#define FINAL_PROJECT_ALIEN_H

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "core/bullet.h"

namespace shooter {

class Alien {
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
   * Moves alien upwards based on movement speed
   */
  void MoveUp();

  /**
   * Moves alien downwards based on movement speed
   */
  void MoveDown();

  /**
   * Moves alien left based on movement speed
   */
  void MoveLeft();

  /**
   * Moves alien right based on movement speed
   */
  void MoveRight();

  /**
   * Returns a Bullet object traveling in the direction of the player in the
   * application window
   *
   * @param player_position - position of the player in the application window
   * @return
   */
  Bullet ShootBullet(const glm::vec2& player_position);

  /**
   * Handles bullet collisions with alien by decrementing HP when struck by a
   * bullet and removing the bullet
   *
   * @param bullets - bullets present in the application
   * @param color - color of the bullets shot by the player
   */
  void HandleCollisions(std::vector<Bullet>* bullets,
                        const ci::Color& bullet_color);

  int GetHealthPoints() const;

  void DecrementHealth();

  glm::vec2 GetPosition() const&;

 private:
  glm::vec2 position_;
  float radius_;
  float movement_speed_;
  int health_points_;
  ci::Color bullet_color_;
};

}  // namespace shooter

#endif  // FINAL_PROJECT_ALIEN_H
