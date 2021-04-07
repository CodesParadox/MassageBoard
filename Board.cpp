#include <iostream>
#include "Board.hpp"
#include <map>
#include "Direction.hpp"
#include <string>
using namespace std;

namespace ariel
{

	void Board::post(u_int row, u_int col, Direction direction, std::string msg)
	{
		this->Max_Raw = max(this->Max_Raw, row);
		this->Max_Col = max(this->Max_Col, col);
		this->Min_Raw = min(this->Min_Raw, row);
		this->Min_Col = min(this->Min_Col, col);
		for (char chr : msg)
		{
			this->board[row][col].ch = chr;
			if (direction == Direction::Vertical)
			{
				row++;
			}
			else
			{
				col++;
			}
		}
	}

	string Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int length)
	{
		string str;

		for (unsigned int i = 0; i < length; i++)
		{
			str = str + this->board[row][col].ch;
			if (direction == Direction::Vertical)
			{
				row++;
			}
			else
			{
				col++;
			}
		}
		return str;
	}

	void Board::show()
	{
		for (unsigned int i = this->Min_Raw; i <= this->Max_Raw; i++)
		{
			for (unsigned int j = this->Min_Col; j <= this->Max_Col; j++)
			{
				cout << this->board[i][j].ch << " ";
			}
			cout << "\n\n\n";
		}
	}

}