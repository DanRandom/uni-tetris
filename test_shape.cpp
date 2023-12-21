#include "catch.hpp"
#include "shape.h"

int testGameGrid[width][height];

void fillTestGameGrid() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; ++y) {
            testGameGrid[x][y] = 0;
        }
    }
}

TEST_CASE("Test Shape constructor") {
    SECTION("Test Shape type and color") {
        Color testColor = RED;
        Shape shape(0, testColor);
        REQUIRE(shape.getType() == 0);
        REQUIRE(shape.getColor().r == testColor.r);
        REQUIRE(shape.getColor().g == testColor.g);
        REQUIRE(shape.getColor().b == testColor.b);
        REQUIRE(shape.getColor().a == testColor.a);
    }
}


TEST_CASE("Test Shape movement") {
    SECTION("Test Shape movement to the right") {
        Shape shape(0, RED);
        fillTestGameGrid();
        shape.move(1, 0, testGameGrid, false);
        REQUIRE(shape.getPositionX() == 1);
    }

}

TEST_CASE("Test Shape boundary check") {
    SECTION("Test Shape inside boundaries") {
        Shape shape(0, RED, 5, 5);
        fillTestGameGrid();
        REQUIRE(shape.isWithinBounds() == true);
    }

    SECTION("Test Shape outside boundaries") {
        Shape shape(0, RED, -10, 17);
        fillTestGameGrid();
        REQUIRE(shape.isWithinBounds() == false);
    }
}
