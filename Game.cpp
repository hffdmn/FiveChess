#include<windows.h>
#include "Game.h"
#include "CheckResult.h"
#include "ComputerNextChess.h"
extern int ChessState[15][15];
using namespace std;

//选择游戏模式
void Game::PlayModel()
{
  ChessTable table;
  system("cls");
  system("color F0");//设置背景色
  cout<<"请输入您要选择的玩法：0--人机模式，1--人人模式。"<<endl;
  do{
      cin>>playmodle;
  }while(!CheckModel(playmodle));

  switch(playmodle)
  {
  case 0:
    Computer2People(table);
    break;
  case 1:
    People2People(table);
    break;
  default:
    break;
  }
}

//人人对弈模块
void Game::People2People(ChessTable &table)
{
  char x,LastX;
  int y,LastY;
  table.Display();
  player=1;
  cout<<"规则：执黑子一方先下，白子后下"<<endl;
  do{
     if(player==1)//黑子
      cout<<endl<<"黑子下：(例如A 1）"<<endl;
     else
      cout<<endl<<"白子下：(例如A 1）"<<endl;
     cin>>x;
     cin>>y;
     if(CheckInput(x,y))
     {
       ChessState[15-y][x-'A']=4-player;//当前子为▼或△
       ChessState [LastY][LastX]= 1+player;//上一个子设置为●或○
       LastX=x-'A';
       LastY=15-y;
       table.Display();
       player=!player;//取反
     }
  } while(CheckResult(x,y)==0);

  DisplayResult(CheckResult(x,y));
}

//人机对弈模块
void Game::Computer2People(ChessTable &table)
{
  char x,LastX;
  int y,LastY;
  int commodel;
  int i=0;
  cout<<"机先请输入0(您将执白子），人先请输入1（您将执黑子）:"<<endl;
  do{
      cin>>commodel;
  }while(!CheckModel(commodel));

  table.Display();
  player=commodel;

  do{
     if(player==1)
     {
       cout<<endl<<"请用户输入当前落子坐标：(例如A 1）"<<endl;
       cin>>x;
       cin>>y;
     }
     else
      {
        x=NextChess(commodel)%15+'A';
        y=15-NextChess(commodel)/15;
      }
     if(CheckInput(x,y))
     {
        if(commodel==0) //计算机执黑子
        {
          ChessState[15-y][x-'A']=3+player;//当前子为▼或△
          ChessState [LastY][LastX]= 2-player;//上一个子设置为●或○
        }
        else if(commodel==1)
        {
          ChessState[15-y][x-'A']=4-player;//当前子为▼或△
          ChessState [LastY][LastX]= 1+player;//上一个子设置为●或○
        }
       LastX=x-'A';
       LastY=15-y;
       table.Display();
       if(player==0)
       cout<<"计算机当前落子坐标为: "<<x<<" "<<y<<endl;
       player=!player;//取反,对方下
    }
  } while(CheckResult(x,y)==0);

  DisplayResult(CheckResult(x,y));
}

