#include <core/player.h>

#include <catch2/catch.hpp>

TEST_CASE("Player movement") {
  shooter::Player player(glm::vec2(500, 500), 0, 20.0f, 5, ci::Color("white"));
  SECTION("MoveUp moves player upward based on movement speed") {
    player.MoveUp();

    REQUIRE(player.GetPosition() == glm::vec2(500, 480));
  }

  SECTION("MoveLeft moves player left based on movement speed") {
    player.MoveLeft();

    REQUIRE(player.GetPosition() == glm::vec2(480, 500));
  }

  SECTION("MoveDown moves player downward based on movement speed") {
    player.MoveDown();

    REQUIRE(player.GetPosition() == glm::vec2(500, 520));
  }

  SECTION("MoveRight moves player right based on movement speed") {
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

TEST_CASE("Player & bullet collisions") {
  SECTION(
      "Single bullet collision removes one HP from Player and erases bullet") {
    ci::Color bullet_color("white");
    std::vector<shooter::Bullet> bullets_;

    bullets_.emplace_back(glm::vec2(600, 600), glm::vec2(-20, -30), 20.0f,
                          bullet_color);
    bullets_.emplace_back(glm::vec2(1000, 1000), glm::vec2(-20, -30), 20.0f,
                          bullet_color);

    shooter::Player player(glm::vec2(500, 500), 150, 20.0f, 5, bullet_color);

    player.HandleCollisions(&bullets_, bullet_color);

    REQUIRE(player.GetHealthPoints() == 4);
    REQUIRE(bullets_.size() == 1);
    REQUIRE(bullets_.at(0).GetPosition() == glm::vec2(1000, 1000));
  }

  SECTION(
      "Single bullet collision removes two HP from Player and erases bullets") {
    ci::Color bullet_color("white");
    std::vector<shooter::Bullet> bullets_;

    bullets_.emplace_back(glm::vec2(600, 600), glm::vec2(-20, -30), 20.0f,
                          bullet_color);
    bullets_.emplace_back(glm::vec2(400, 400), glm::vec2(-20, -30), 20.0f,
                          bullet_color);

    shooter::Player player(glm::vec2(500, 500), 150, 20.0f, 5, bullet_color);

    player.HandleCollisions(&bullets_, bullet_color);

    REQUIRE(player.GetHealthPoints() == 3);
    REQUIRE(bullets_.size() == 0);
  }

  SECTION(
      "Player and bullet do not collide, no HP removed and bullet not erased") {
    ci::Color bullet_color("white");
    std::vector<shooter::Bullet> bullets_;

    bullets_.emplace_back(glm::vec2(700, 700), glm::vec2(-20, -30), 20.0f,
                          bullet_color);

    shooter::Player player(glm::vec2(500, 500), 150, 20.0f, 5, bullet_color);

    player.HandleCollisions(&bullets_, bullet_color);

    REQUIRE(player.GetHealthPoints() == 5);
    REQUIRE(bullets_.size() == 1);
  }
}
