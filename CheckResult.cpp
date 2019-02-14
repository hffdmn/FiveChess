#include<iostream>
#include "CheckResult.h"
#include "ComputerNextChess.h"
using namespace std;
extern int ChessState[15][15];
extern int dx[8];
extern int dy[8];
//ѡ����Ϸģʽʱ��ֹ����Ƿ��ַ�
int CheckModel(int model)
{
  if(model==0||model==1)
  {
    return 1;
  }
  else
  {
    cout<<"������Ϸ��ַ�:0��1"<<endl;
    return 0;
  }
}

//������������ʱ��ֹ����Ƿ��ַ�
int CheckInput(char x,int y)
{
  if(x>'O'||x<'A'||y>15||y<1)
  {
    cout<<"������Ϸ��ĸ�ʽ��"<<endl;
    return 0;
  }
  else if(ChessState[15-y][x-'A']!=0)
  {
    cout<<"��λ���������ӣ�����������"<<endl;
    return 0;
  }
  else
    return 1;
}

//������(x,y)������鵱ǰս��
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
  //����Ƿ��γ�5��
  for(u=0;u<8;u++)
  {
    if(num(RealX,RealY,u,player)+same(RealX,RealY,u,player)==4)
      return player;
  }
//������Ӻ�����Ƿ��γɽ���
  if(player==1)
  {
    for(m=0;m<15;m++)
    {
      for(n=0;n<15;n++)
      {
        if (!ok(m,n))
          continue;
        if(ban(m, n,1)) //��������γɽ���ͼ�Σ���¼����λ��
        {
          if(RealX==m&& RealY==n)
          {
            cout<<"�����γ��˽���"<<endl;
            return 2;
          }
        }
      }
    }
   }

//��������Ƿ�������������
	for (m = 0;m < 15;m++)
  {
		for (n = 0;n < 15;n++)
		{
			if (ChessState[m][n] == 0)
			{
				flag = 1;
				break;
			}
      if (flag)//�������ѭ��
			break;
		}
 }
	if (m == 15 && n == 15)
		return 3;//�;�

  return 0;
}

//���ʤ�����
void DisplayResult(int result)
{
  switch (result)
  {
	case 1:
		cout<< "���ֽ���������ʤ��"<<endl;
		break;
	case 2:
		cout<< "���ֽ���������ʤ��"<<endl;
		break;
	case 3:
		cout<< "���ֽ��������Ǵ�ƽ"<<endl;
		break;
	default:
		break;
	}
}
