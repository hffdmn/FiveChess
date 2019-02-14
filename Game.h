#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "ChessTable.h"
class Game
{
private:
  int player;
  int playmodle;
  ChessTable table;
public:
  void People2People(ChessTable &table);
  void Computer2People(ChessTable &table);
  void PlayModel();

};


#endif // GAME_H_INCLUDED
