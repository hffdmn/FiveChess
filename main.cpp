#include <iostream>
#include <stdlib.h>
#include "Game.h"
using namespace std;
int ChessState[15][15]={0};
int main()
{
  Game i;
  i.PlayModel();
  system("PAUSE");
  return 0;
}
