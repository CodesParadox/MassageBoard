#include "doctest.h"
#include "Board.hpp"
#include <string>
using namespace std;
using namespace ariel;

#include "Direction.hpp"
#include "doctest.h"
#include "Board.hpp"
#include <string>
using namespace std;
using ariel::Direction;

ariel::Board board;

TEST_CASE("Empty Board")
{
    CHECK(board.read(10, 12, Direction::Horizontal, 5) == string("_____"));
    CHECK(board.read(13, 10, Direction::Vertical, 1) == string("_"));
}

TEST_CASE("read word with length 0")
{
    CHECK(board.read(15, 10, Direction::Horizontal, 0) == string(""));
    CHECK(board.read(25, 15, Direction::Vertical, 0) == string(""));
}

TEST_CASE("Post Out Range")
{

    CHECK_NOTHROW(board.post(0, 1000, Direction::Horizontal, "G"));
    CHECK_NOTHROW(board.post(0, 1500, Direction::Horizontal, "A"));
    CHECK_NOTHROW(board.post(0, 2000, Direction::Horizontal, "L"));
    CHECK_NOTHROW(board.post(1000, 1000, Direction::Vertical, "G"));
    CHECK_NOTHROW(board.post(1500, 1500, Direction::Vertical, "A"));
    CHECK_NOTHROW(board.post(2000, 2000, Direction::Vertical, "L"));
}

TEST_CASE("Read Out Range")
{
    CHECK_NOTHROW(board.read(0, 1000, Direction::Horizontal, 10));
    CHECK_NOTHROW(board.read(0, 1500, Direction::Horizontal, 10));
    CHECK_NOTHROW(board.read(0, 2000, Direction::Horizontal, 10));
    CHECK_NOTHROW(board.read(1000, 0, Direction::Vertical, 5));
    CHECK_NOTHROW(board.read(1500, 0, Direction::Vertical, 5));
    CHECK_NOTHROW(board.read(2000, 0, Direction::Vertical, 5));
}

TEST_CASE("read in place bigger than size")
{
    CHECK(board.read(0, 3, Direction::Horizontal, 5) == string("_____"));
}

TEST_CASE("Overide number of strings")
{
    board.post(0, 0, Direction::Horizontal, "To much time on this");
    board.post(1, 0, Direction::Horizontal, "WHY?");
    board.post(0, 2, Direction::Vertical, "IDK");
    CHECK(board.read(0, 0, Direction::Horizontal, 12) == "To much time");
    CHECK(board.read(0, 0, Direction::Vertical, 5) == "TW___");
    CHECK(board.read(0, 2, Direction::Vertical, 3) == "IDK");
}