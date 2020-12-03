#include <core/player.h>

#include <catch2/catch.hpp>

TEST_CASE("Player movement") {
  SECTION("MoveUp moves player upward based on movement speed") {
    shooter::Player player(glm::vec2(500, 500), 0, 20.0f, 5,
                           ci::Color("white"));

    player.MoveUp();

    REQUIRE(player.GetPosition() == glm::vec2(500, 480));
  }

  SECTION("MoveLeft moves player left based on movement speed") {
    shooter::Player player(glm::vec2(500, 500), 0, 20.0f, 5,
                           ci::Color("white"));

    player.MoveLeft();

    REQUIRE(player.GetPosition() == glm::vec2(480, 500));
  }

  SECTION("MoveDown moves player downward based on movement speed") {
    shooter::Player player(glm::vec2(500, 500), 0, 20.0f, 5,
                           ci::Color("white"));

    player.MoveDown();

    REQUIRE(player.GetPosition() == glm::vec2(500, 520));
  }

  SECTION("MoveRight moves player right based on movement speed") {
    shooter::Player player(glm::vec2(500, 500), 0, 20.0f, 5,
                           ci::Color("white"));

    player.MoveRight();

    REQUIRE(player.GetPosition() == glm::vec2(520, 500));
  }
}

TEST_CASE("Player bullet shooting") {
  SECTION("Player bullet shot correctly") {
    shooter::Player player(glm::vec2(500, 500), 0, 20.0f, 5,
                           ci::Color("white"));

    shooter::Bullet bullet = player.ShootBullet(glm::ivec2(1000, 1000));

    REQUIRE(bullet.GetVelocity() == glm::vec2(2 * 14.1421337, 2 * 14.1421337));
  }
}
