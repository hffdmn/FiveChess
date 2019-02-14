#include<windows.h>
#include "Game.h"
#include "CheckResult.h"
#include "ComputerNextChess.h"
extern int ChessState[15][15];
using namespace std;

//ѡ����Ϸģʽ
void Game::PlayModel()
{
  ChessTable table;
  system("cls");
  system("color F0");//���ñ���ɫ
  cout<<"��������Ҫѡ����淨��0--�˻�ģʽ��1--����ģʽ��"<<endl;
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

//���˶���ģ��
void Game::People2People(ChessTable &table)
{
  char x,LastX;
  int y,LastY;
  table.Display();
  player=1;
  cout<<"����ִ����һ�����£����Ӻ���"<<endl;
  do{
     if(player==1)//����
      cout<<endl<<"�����£�(����A 1��"<<endl;
     else
      cout<<endl<<"�����£�(����A 1��"<<endl;
     cin>>x;
     cin>>y;
     if(CheckInput(x,y))
     {
       ChessState[15-y][x-'A']=4-player;//��ǰ��Ϊ�����
       ChessState [LastY][LastX]= 1+player;//��һ��������Ϊ����
       LastX=x-'A';
       LastY=15-y;
       table.Display();
       player=!player;//ȡ��
     }
  } while(CheckResult(x,y)==0);

  DisplayResult(CheckResult(x,y));
}

//�˻�����ģ��
void Game::Computer2People(ChessTable &table)
{
  char x,LastX;
  int y,LastY;
  int commodel;
  int i=0;
  cout<<"����������0(����ִ���ӣ�������������1������ִ���ӣ�:"<<endl;
  do{
      cin>>commodel;
  }while(!CheckModel(commodel));

  table.Display();
  player=commodel;

  do{
     if(player==1)
     {
       cout<<endl<<"���û����뵱ǰ�������꣺(����A 1��"<<endl;
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
        if(commodel==0) //�����ִ����
        {
          ChessState[15-y][x-'A']=3+player;//��ǰ��Ϊ�����
          ChessState [LastY][LastX]= 2-player;//��һ��������Ϊ����
        }
        else if(commodel==1)
        {
          ChessState[15-y][x-'A']=4-player;//��ǰ��Ϊ�����
          ChessState [LastY][LastX]= 1+player;//��һ��������Ϊ����
        }
       LastX=x-'A';
       LastY=15-y;
       table.Display();
       if(player==0)
       cout<<"�������ǰ��������Ϊ: "<<x<<" "<<y<<endl;
       player=!player;//ȡ��,�Է���
    }
  } while(CheckResult(x,y)==0);

  DisplayResult(CheckResult(x,y));
}

