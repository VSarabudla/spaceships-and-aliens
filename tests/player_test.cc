#include <core/player.h>

#include <catch2/catch.hpp>

TEST_CASE("WASD Movement") {
  SECTION("W movement interpreted correctly") {
    shooter::Player player(glm::vec2(500, 500), 20.0f);

    player.UpdatePosition(ci::app::KeyEvent(nullptr,
                                            ci::app::KeyEvent::KEY_w,
                                            0,
                                            0,
                                            0,
                                            0));

    REQUIRE(player.GetPosition() == glm::vec2(500, 480));
  }

  SECTION("A movement interpreted correctly") {
    shooter::Player player(glm::vec2(500, 500), 20.0f);

    player.UpdatePosition(ci::app::KeyEvent(nullptr,
                                            ci::app::KeyEvent::KEY_a,
                                            0,
                                            0,
                                            0,
                                            0));

    REQUIRE(player.GetPosition() == glm::vec2(480, 500));
  }

  SECTION("S movement interpreted correctly") {
    shooter::Player player(glm::vec2(500, 500), 20.0f);

    player.UpdatePosition(ci::app::KeyEvent(nullptr,
                                            ci::app::KeyEvent::KEY_s,
                                            0,
                                            0,
                                            0,
                                            0));

    REQUIRE(player.GetPosition() == glm::vec2(500, 520));
  }

  SECTION("D movement interpreted correctly") {
    shooter::Player player(glm::vec2(500, 500), 20.0f);

    player.UpdatePosition(ci::app::KeyEvent(nullptr,
                                            ci::app::KeyEvent::KEY_d,
                                            0,
                                            0,
                                            0,
                                            0));

    REQUIRE(player.GetPosition() == glm::vec2(520, 500));
  }

  SECTION("G movement interpreted correctly") {
    shooter::Player player(glm::vec2(500, 500), 20.0f);

    player.UpdatePosition(ci::app::KeyEvent(nullptr,
                                            ci::app::KeyEvent::KEY_g,
                                            0,
                                            0,
                                            0,
                                            0));

    REQUIRE(player.GetPosition() == glm::vec2(500, 500));
  }
}

TEST_CASE("Bullet shooting") {
  SECTION("Bullet shot correctly") {
    shooter::Player player(glm::vec2(500, 500), 20.0f);

    shooter::Bullet bullet = player.ShootBullet(glm::ivec2(1000, 1000));

    REQUIRE(bullet.GetVelocity() == glm::vec2(14.1421337, 14.1421337));
  }
}
