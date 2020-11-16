#include "visualizer/shooter_app.h"

void shooter::visualizer::ShooterApp::update() {
  AppBase::update();
}

void shooter::visualizer::ShooterApp::draw() {
  AppBase::draw();
}

void shooter::visualizer::ShooterApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_w:

      break;
    case ci::app::KeyEvent::KEY_a:
      break;
    case ci::app::KeyEvent::KEY_s:
      break;
    case ci::app::KeyEvent::KEY_d:
      break;
  }
}
