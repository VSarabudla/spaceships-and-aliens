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
   * Moves player upwards based on movement speed
   */
  void MoveUp();

  /**
   * Moves player downwards based on movement speed
   */
  void MoveDown();

  /**
   * Moves player left based on movement speed
   */
  void MoveLeft();

  /**
   * Moves player right based on movement speed
   */
  void MoveRight();

  /**
   * Returns a Bullet object traveling in the direction where the user clicks in
   * the application window
   *
   * @param mouse_position
   * @return Bullet traveling in the direction where the user clicks
   */
  Bullet ShootBullet(const ci::ivec2& mouse_position);

  /**
   * Handles bullet collisions with player by decrementing HP when struck by a
   * bullet and removing the bullet
   *
   * @param bullets - bullets present in the application
   * @param color - color of the bullets shot by the aliens
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

#endif  // FINAL_PROJECT_PLAYER_H
