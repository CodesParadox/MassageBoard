
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

struct noChar
{
	char ch = '_';
};

namespace ariel
{
	class Board
	{
	private:
		map<unsigned int, map<unsigned int, noChar>> board;
		unsigned int Min_Col, Max_Col, Min_Raw, Max_Raw;

	public:
		Board() // Creating new empty board -> constructor
		{
			Max_Col = Max_Raw = 0;
			Min_Col = Min_Raw = INF;
		}
		~Board() {} // destructor
		void post(u_int row, u_int column, Direction direction, std::string msg);

		std::string read(u_int row, u_int column, Direction direction, u_int length);

		void show();
	};
}
