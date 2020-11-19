#ifndef FINAL_PROJECT_SHOOTER_APP_H
#define FINAL_PROJECT_SHOOTER_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "core/player.h"

namespace shooter {

namespace visualizer {

/**
 * 2D-shooter where a player fights against aliens
 */
class ShooterApp : public ci::app::App {
 public:
  ShooterApp();

  void update() override;
  void draw() override;
  void keyDown(ci::app::KeyEvent event) override;
  void mouseDown(ci::app::MouseEvent event) override;

  const float kPlayerMovementSpeed = 20;

 private:
  Player player_;
  std::vector<Bullet> projectiles_;
};

}  // namespace visualizer

}  // namespace shooter

#endif  // FINAL_PROJECT_SHOOTER_APP_H
