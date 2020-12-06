#ifndef FINAL_PROJECT_SHOOTER_APP_H
#define FINAL_PROJECT_SHOOTER_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/audio/audio.h"
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

  const int kPlayerHealthPoints = 5;
  const float kPlayerMovementSpeed = 10;
  const ci::Color kPlayerBulletColor = ci::Color("white");

  const int kAlienHealthPoints = 5;
  const float kAlienMovementSpeed = 2;
  const float kAlienBulletMovementSpeed = 15;
  const ci::Color kAlienBulletColor = ci::Color8u(70, 100, 0);

  // seconds between aliens spawning
  const double kAlienSpawnRate = 2.0;

  /**
   * Computes the angle between two vectors in radians
   *
   * @param a - vector a
   * @param b - vector b
   * @return - angle between a & b in radians
   */
  static float AngleBetween(const glm::vec2& a, const glm::vec2& b);

 private:
  /**
   * Draws player sprite in application window
   */
  void DrawPlayer();

  /**
   * Draws a given alien's sprite in application window
   */
  void DrawAlien(const Alien& alien);

  /**
   * Draws a heads-up display
   */
  void DrawHUD();

  Player player_;
  ci::gl::TextureRef player_sprite_;
  ci::audio::VoiceRef player_shooting_sound_;
  ci::gl::TextureRef alien_sprite_;
  std::vector<Alien> aliens_;
  std::vector<Bullet> projectiles_;
  std::set<int> held_keys_;
  ci::Timer event_timer_;
  int score_;
  ci::Font hud_font_;
};

}  // namespace visualizer

}  // namespace shooter

#endif  // FINAL_PROJECT_SHOOTER_APP_H
