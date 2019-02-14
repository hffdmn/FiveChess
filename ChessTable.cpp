#include <iostream>
#include<windows.h>
#include <iomanip>//set()函数需要
#include "ChessTable.h"
extern int ChessState[15][15];
using namespace std;

//打印棋盘
void ChessTable::Display()
{
  system("cls");
  int row,colomn;
   for (int row = 0;row < 15;row++)
    {
    cout << setw(3)<<15-row;
		for (int column = 0;column < 15;column++)
		 {
			switch (ChessState[row][column])
			{
				case 0:
          cout << Chess[row][column*3]<<Chess[row][column*3+1]<<Chess[row][column*3+2];//unicode 2个字节
          break;
				case 1:
					cout << "●";
					break;
				case 2:
					cout << "○";
					break;
				case 3:
					cout << "▲";
					break;
				case 4:
					cout << "△";
					break;
				default:
					break;
			}
		}
		cout << endl;
	}
	cout<<"   A B C D E F G H I J K L M N O"<<endl;
}

