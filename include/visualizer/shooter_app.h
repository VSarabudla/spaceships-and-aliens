#ifndef FINAL_PROJECT_SHOOTER_APP_H
#define FINAL_PROJECT_SHOOTER_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "core/alien.h"
#include "core/player.h"

namespace shooter {

namespace visualizer {

/**
 * 2D-shooter where a player fights against aliens
 */
class ShooterApp : public ci::app::App {
 public:
  ShooterApp();

  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(ci::app::KeyEvent event) override;
  void keyUp(ci::app::KeyEvent event) override;
  void mouseDown(ci::app::MouseEvent event) override;

  const float kPlayerMovementSpeed = 10;

 private:
  /**
   * Draws player sprite in application window
   */
  void DrawPlayer();

  /**
   * Draws a given alien's sprite in application window
   */
  void DrawAlien(const Alien& alien);

  float AngleBetween(const glm::vec2& a, const glm::vec2& b);

  Player player_;
  ci::gl::TextureRef player_sprite_;
  ci::gl::TextureRef alien_sprite_;
  std::vector<Alien> aliens_;
  std::vector<Bullet> projectiles_;
  std::set<int> held_keys_;
};

}  // namespace visualizer

}  // namespace shooter

#endif  // FINAL_PROJECT_SHOOTER_APP_H
