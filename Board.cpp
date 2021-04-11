#include <iostream>
#include "Board.hpp"
#include <map>
#include "Direction.hpp"
#include <string>
using namespace std;

namespace ariel
{
	/* Posting a string type method on the board, by given coordinates, direction and the string of the post */

	void Board::post(u_int row, u_int col, Direction direction, std::string msg)
	{
		/* gvulot from what i have to what i get */
		this->Max_Raw = max(this->Max_Raw, row);
		this->Max_Col = max(this->Max_Col, col);
		this->Min_Raw = min(this->Min_Raw, row);
		this->Min_Col = min(this->Min_Col, col);

		// for( int i=0; i< msg.length(); i++){
		// 	this->board[row][col].ch = msg.at(i);
		// 	if (direction == Direction::Vertical)
		// 	{
		// 		row++;
		// 	}
		// 	else
		// 	{
		// 		col++;
		// 	}
		// }
		if (msg.length() >= 1) // check if the string is empty
		{

			for (char chr : msg) // posting -> check each char
			{
				this->board[row][col].ch = chr;
				//marking the direction using a boolean for easy redirection
				if (direction == Direction::Vertical) // if its vertical move row otherwise col
				{
					row++;
				}
				else
				{
					col++;
				}
			}
		}
	}

	/* Reading from the board by coordinates, direction and length */
	string Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int length)
	{
		string str;
		if (length == 0)
		{
			return str;
		}
		else
		{
			for (unsigned int i = 0; i < length; i++) // move on the input length
			{
				str = str + this->board[row][col].ch; // hashmap in hashmap
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
	}

	/**
     * Converts the map board to an output on screen including row numbers on the left side of the board itself.
     * Print the board while empty cell is "_"
     * */
	void Board::show()
	{
		for (unsigned int i = this->Min_Raw; i <= this->Max_Raw; i++) // move from the min char to the max
		{
			for (unsigned int j = this->Min_Col; j <= this->Max_Col; j++)
			{
				cout << this->board[i][j].ch << " "; // put space after finish
			}
			cout << "\n\n";
		}
	}

}

// void showMenu(){
// 	cout << "***********Menu**********" <<endl;
// 	cout << "1. read post" << endl;
// 	cout << "2. Post" << endl;
// 	cout << "3. Show Post" << endl;
// 	cout << "*************************" << endl;
// }
// int main(){
//	do{
// 	int choice;
// 	int row, col;
// 	string str="";
// 	showMenu();
// 	cout <<"Pick your choice: ";
// 	cin >> choice;
//	}
// 	switch(choice){
// 		case 1:
// 		string Board::read();
// 		break;
// 		case 2: cout<< "Posting: ";
// 		cin>> row;
// 		cin >> col;
// 		cin>> str;
// 		break;
// 		case 3:
// 		show();
// 		break;
//		case 0:
//			break;
//

// 	}while(choice !=0){
//};
// 	system("pause>0");

// }