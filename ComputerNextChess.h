#ifndef COMPUTERNEXTCHESS_H_INCLUDED
#define COMPUTERNEXTCHESS_H_INCLUDED
int ChessPlayer(int player);
int inboard(int row, int col);
int ok(int row, int col);
int num(int row, int col, int u,int color);
int same(int row, int col, int u,int color);
int overline(int row,int col,int color);;
int live4(int row,int col,int color);
int chong4(int row,int col,int color);
int live3(int row,int col,int color);
int die3(int row,int col,int color);
int live2(int row,int col,int color);
int ban(int row, int col,int color);
int Calculate(int row, int col,int color);
int NextChess(int commodle);
#endif // COMPUTERNEXTCHESS_H_INCLUDED
