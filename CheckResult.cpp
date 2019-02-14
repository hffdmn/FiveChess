#include<iostream>
#include "CheckResult.h"
#include "ComputerNextChess.h"
using namespace std;
extern int ChessState[15][15];
extern int dx[8];
extern int dy[8];
//选择游戏模式时防止输入非法字符
int CheckModel(int model)
{
  if(model==0||model==1)
  {
    return 1;
  }
  else
  {
    cout<<"请输入合法字符:0或1"<<endl;
    return 0;
  }
}

//输入落子坐标时防止输入非法字符
int CheckInput(char x,int y)
{
  if(x>'O'||x<'A'||y>15||y<1)
  {
    cout<<"请输入合法的格式！"<<endl;
    return 0;
  }
  else if(ChessState[15-y][x-'A']!=0)
  {
    cout<<"该位置已有棋子！请重新输入"<<endl;
    return 0;
  }
  else
    return 1;
}

//当落在(x,y)坐标后检查当前战况
int CheckResult(char x,int y)
{
  int flag;
  int i;
  int m,n,u,temp;
  int RealX,RealY;
  RealY=x-'A';
  RealX=15-y;
  int player;
  temp=ChessState[RealX][RealY];
  player=ChessPlayer(ChessState[RealX][RealY]);
  //检查是否形成5连
  for(u=0;u<8;u++)
  {
    if(num(RealX,RealY,u,player)+same(RealX,RealY,u,player)==4)
      return player;
  }
//检查落子后黑子是否形成禁手
  if(player==1)
  {
    for(m=0;m<15;m++)
    {
      for(n=0;n<15;n++)
      {
        if (!ok(m,n))
          continue;
        if(ban(m, n,1)) //如果黑子形成禁手图形，记录禁手位置
        {
          if(RealX==m&& RealY==n)
          {
            cout<<"黑子形成了禁手"<<endl;
            return 2;
          }
        }
      }
    }
   }

//检查棋子是否布满了整个棋盘
	for (m = 0;m < 15;m++)
  {
		for (n = 0;n < 15;n++)
		{
			if (ChessState[m][n] == 0)
			{
				flag = 1;
				break;
			}
      if (flag)//跳出外层循环
			break;
		}
 }
	if (m == 15 && n == 15)
		return 3;//和局

  return 0;
}

//输出胜负结果
void DisplayResult(int result)
{
  switch (result)
  {
	case 1:
		cout<< "本局结束，黑子胜利"<<endl;
		break;
	case 2:
		cout<< "本局结束，白子胜利"<<endl;
		break;
	case 3:
		cout<< "本局结束，你们打平"<<endl;
		break;
	default:
		break;
	}
}
