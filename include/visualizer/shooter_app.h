#ifndef FINAL_PROJECT_SHOOTER_APP_H
#define FINAL_PROJECT_SHOOTER_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "core/player.h"

namespace shooter {

namespace visualizer {

class ShooterApp: public ci::app::App {
 public:
  ShooterApp() = default;

  void update() override;
  void draw() override;
  void keyDown(ci::app::KeyEvent event) override;

 private:

};

} // namespace visualizer

} // namespace shooter

#endif //FINAL_PROJECT_SHOOTER_APP_H
