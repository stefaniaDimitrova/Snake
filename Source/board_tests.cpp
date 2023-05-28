// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "../Headers/doctest.h"
// #include "../Headers/board.hpp"

// TEST_CASE("Board Tests")
// {
//     // Test case for setting and getting cell values
//     SUBCASE("Set and Get Cell")
//     {
//         Board board;
//         Point position(2, 3);
//         char symbol = '#';

//         board.setCell(position, symbol);
//         CHECK(board.getCell(position) == symbol);
//     }

//     // Test case for checking if a position is within the board boundaries
//     SUBCASE("Not Border")
//     {
//         Board board;
//         board.setWidth(5);
//         board.setHeight(5);

//         CHECK(board.notBorder(Point(3, 3)) == true);  // Inside the board boundaries
//         CHECK(board.notBorder(Point(0, 0)) == false);  // On the border
//         CHECK(board.notBorder(Point(5, 5)) == false); // Outside the board boundaries
//     }
// }
