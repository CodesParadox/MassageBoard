#include <iostream>
#pragma once
#include "Direction.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <limits>
using namespace std;

const uint INF = std::numeric_limits<uint>::max();

// Defult values in map of char
struct noChar
{
	char ch = '_'; // defult char
};

namespace ariel
{
	class Board
	{
		/*  a map of maps of chars. contains the posted chars.
		Min_Col, Max_Col, Min_Raw, Max_Raw -> marking the borders of the whole board to keeping it small */
	private:
		map<unsigned int, map<unsigned int, noChar>> board;
		unsigned int Min_Col, Max_Col, Min_Raw, Max_Raw;

	public:
		Board() // Creating new empty board -> constructor
		{
			Max_Col = Max_Raw = 0;   //Max col and row -> set initially to 0
			Min_Col = Min_Raw = INF; // Max col and row -> set initially to max value of uint.
		}
		~Board() {} // destructor -> create board as it come out of context
		void post(u_int row, u_int column, Direction direction, std::string msg);

		std::string read(u_int row, u_int column, Direction direction, u_int length);

		void show();
	};
}