#ifndef FINAL_PROJECT_CHARACTER_H
#define FINAL_PROJECT_CHARACTER_H

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "core/bullet.h"

namespace shooter {

class Character {
 public:
  Character() = default;

  /**
   * Creates a Character object
   *
   * @param position - position of character
   * @param radius - radius of character sprite
   * @param movement_speed - movement speed of character
   * @param health_points - health points of character
   */
  Character(const glm::vec2& position, float radius, float movement_speed,
            int health_points);

  /**
   * Moves character upwards based on movement speed
   */
  void MoveUp();

  /**
   * Moves character downwards based on movement speed
   */
  void MoveDown();

  /**
   * Moves character left based on movement speed
   */
  void MoveLeft();

  /**
   * Moves character right based on movement speed
   */
  void MoveRight();

  /**
   * Handles bullet collisions with character by decrementing HP when struck by
   * a bullet and removing the bullet
   *
   * @param bullets - bullets present in the application
   * @param color - color of the bullets shot by the player
   */
  void HandleCollisions(std::vector<Bullet>* bullets,
                        const ci::Color& bullet_color);

  void DecrementHealth();

  glm::vec2 GetPosition() const&;

  int GetHealthPoints() const;

 protected:
  glm::vec2 position_;
  float radius_;
  float movement_speed_;
  int health_points_;
};

}  // namespace shooter

#endif  // FINAL_PROJECT_CHARACTER_H
