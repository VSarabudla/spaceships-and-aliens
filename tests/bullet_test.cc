#include <core/bullet.h>

#include <catch2/catch.hpp>

TEST_CASE("Basic bullet movement") {
  SECTION("Bullet with velocity moves correctly") {
    shooter::Bullet bullet(glm::vec2(500, 500), glm::vec2(-20, -30), 20.0f,
                           ci::Color("white"));
    bullet.UpdatePosition();
    glm::vec2 position = bullet.GetPosition();
    REQUIRE(position.x == 480);
    REQUIRE(position.y == 470);

    glm::vec2 velocity = bullet.GetVelocity();
    REQUIRE(velocity.x == -20);
    REQUIRE(velocity.y == -30);
  }

  SECTION("Bullet with no velocity moves correctly") {
    glm::vec2 init_position(500, 500);
    shooter::Bullet bullet(init_position, glm::vec2(0, 0), 20.0f,
                           ci::Color("white"));
    bullet.UpdatePosition();
    REQUIRE(init_position == bullet.GetPosition());

    glm::vec2 velocity = bullet.GetVelocity();
    REQUIRE(velocity.x == 0);
    REQUIRE(velocity.y == 0);
  }
}
