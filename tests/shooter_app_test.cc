#include <visualizer/shooter_app.h>

#include <catch2/catch.hpp>

TEST_CASE("AngleBetween") {
  SECTION("Angle between two vectors in a right angle calculated correctly") {
    float test_angle = shooter::visualizer::ShooterApp::AngleBetween(
        glm::vec2(500, 0), glm::vec2(0, 500));
    REQUIRE(test_angle == Approx(-M_PI / 2));
  }

  SECTION("Angle between two non-collinear vectors calculated correctly") {
    float test_angle = shooter::visualizer::ShooterApp::AngleBetween(
        glm::vec2(500, 0), glm::vec2(500, 500));
    REQUIRE(test_angle == Approx(-M_PI / 4));
  }

  SECTION(
      "Angle between two oppositely pointing vectors calculated correctly") {
    float test_angle = shooter::visualizer::ShooterApp::AngleBetween(
        glm::vec2(500, 0), glm::vec2(-500, 0));
    REQUIRE(test_angle == Approx(-M_PI));
  }

  SECTION("Angle between two collinear vectors calculated correctly") {
    float test_angle = shooter::visualizer::ShooterApp::AngleBetween(
        glm::vec2(500, 0), glm::vec2(1, 0));
    REQUIRE(test_angle == Approx(0));
  }
}
