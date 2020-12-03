#include <core/alien.h>

#include <catch2/catch.hpp>

TEST_CASE("Alien movement") {
  SECTION("MoveUp moves alien upward based on movement speed") {
    shooter::Alien alien(glm::vec2(500, 500), 0, 20.0f, 5, ci::Color("white"));

    alien.MoveUp();

    REQUIRE(alien.GetPosition() == glm::vec2(500, 480));
  }

  SECTION("MoveLeft moves alien left based on movement speed") {
    shooter::Alien alien(glm::vec2(500, 500), 0, 20.0f, 5, ci::Color("white"));

    alien.MoveLeft();

    REQUIRE(alien.GetPosition() == glm::vec2(480, 500));
  }

  SECTION("MoveDown moves alien downward based on movement speed") {
    shooter::Alien alien(glm::vec2(500, 500), 0, 20.0f, 5, ci::Color("white"));

    alien.MoveDown();

    REQUIRE(alien.GetPosition() == glm::vec2(500, 520));
  }

  SECTION("MoveRight moves alien right based on movement speed") {
    shooter::Alien alien(glm::vec2(500, 500), 0, 20.0f, 5, ci::Color("white"));

    alien.MoveRight();

    REQUIRE(alien.GetPosition() == glm::vec2(520, 500));
  }
}

TEST_CASE("Alien bullet shooting") {
  SECTION("Alien bullet shot correctly") {
    shooter::Alien alien(glm::vec2(500, 500), 0, 20.0f, 5, ci::Color("white"));

    shooter::Bullet bullet = alien.ShootBullet(glm::vec2(0, 0));

    REQUIRE(bullet.GetVelocity() == glm::vec2(-14.1421337, -14.1421337));
  }
}

TEST_CASE("Alien & bullet collisions") {
  SECTION(
      "Single bullet collision removes one HP from Alien and erases bullet") {
    ci::Color bullet_color("white");
    std::vector<shooter::Bullet> bullets_;

    bullets_.emplace_back(glm::vec2(600, 600), glm::vec2(-20, -30), 20.0f,
                          bullet_color);
    bullets_.emplace_back(glm::vec2(1000, 1000), glm::vec2(-20, -30), 20.0f,
                          bullet_color);

    shooter::Alien alien(glm::vec2(500, 500), 150, 20.0f, 5, bullet_color);

    alien.HandleCollisions(&bullets_, bullet_color);

    REQUIRE(alien.GetHealthPoints() == 4);
    REQUIRE(bullets_.size() == 1);
    REQUIRE(bullets_.at(0).GetPosition() == glm::vec2(1000, 1000));
  }

  SECTION(
      "Single bullet collision removes two HP from Alien and erases bullets") {
    ci::Color bullet_color("white");
    std::vector<shooter::Bullet> bullets_;

    bullets_.emplace_back(glm::vec2(600, 600), glm::vec2(-20, -30), 20.0f,
                          bullet_color);
    bullets_.emplace_back(glm::vec2(400, 400), glm::vec2(-20, -30), 20.0f,
                          bullet_color);

    shooter::Alien alien(glm::vec2(500, 500), 150, 20.0f, 5, bullet_color);

    alien.HandleCollisions(&bullets_, bullet_color);

    REQUIRE(alien.GetHealthPoints() == 3);
    REQUIRE(bullets_.size() == 0);
  }

  SECTION(
      "Alien and bullet do not collide, no HP removed and bullet not erased") {
    ci::Color bullet_color("white");
    std::vector<shooter::Bullet> bullets_;

    bullets_.emplace_back(glm::vec2(700, 700), glm::vec2(-20, -30), 20.0f,
                          bullet_color);

    shooter::Alien alien(glm::vec2(500, 500), 150, 20.0f, 5, bullet_color);

    alien.HandleCollisions(&bullets_, bullet_color);

    REQUIRE(alien.GetHealthPoints() == 5);
    REQUIRE(bullets_.size() == 1);
  }
}
