#include<iostream>
#include "ComputerNextChess.h"
using namespace std;
extern int ChessState[15][15];
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1}; //flat����
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1};

/*�������״̬�������1��3��ʾ�Ǻ��ӣ�2��4��ʾ�ǰ���*/
int ChessPlayer(int player)
{
  switch(player)
  {
  case 1:
  case 3:
    return 1;//����Ϊ1
    break;
  case 2:
  case 4:
    return 2;//����Ϊ2
    break;
  default:
    return 0;
		break;
  }
}

int inboard(int row, int col)//�Ƿ���������
{
	if (row <0 || row > 14 ||col<0 || col >14)
    return 0;
  else
    return 1;
}
int ok(int row, int col)//�ô��ܷ����� �ܷ���1�����򷵻�0
{
  if((inboard(row, col)) && (ChessState[row][col] == 0))
    return 1;
	else
    return 0;
}

//���꣨row,col������������u��ͳ����ͬ��������
int num(int row, int col, int u,int color)
{
	int i = row + dx[u];
	int j = col + dy[u];
  int sum = 0;
	while ((ChessPlayer(ChessState[i][j]) == color)&&(inboard(i,j)))
  {
    sum++;
    i += dx[u];
    j += dy[u];
  }
	return sum;
}
//ͳ��u�ĸ�������ͬ��������
int same(int row, int col, int u,int color)
{
	int i = row - dx[u];
	int j = col - dy[u];
  int sum = 0;
	while ((ChessPlayer(ChessState[i][j]) == color)&&(inboard(i,j)))
  {
    sum++;
    i -= dx[u];
    j -= dy[u];
  }
	return sum;
}
//�������
int overline(int row,int col,int color)
{
  int u;
  int sum=0;
	for (u = 0; u < 8; u++)
	{
    if (num(row, col, u ,color) + same(row, col, u, color ) >=5)
      sum++;
	}
	return sum;
}
//��4���
int live4(int row,int col,int color)
{
  int u;
  int sum=0;
  for (u = 0; u < 8; u++)
  {
    if (ok(row+5*dx[u],col+5*dy[u])&&num(row, col, u,color) == 4)
      sum++;
  }
  return sum;
}
//��4���
int chong4(int row,int col,int color)
{
  int u;
  int sum=0;
  for (u = 0; u < 4; u++)
  {
    if(num(row, col, u, color)+num(row, col, u+4, color)==4)
        sum++;
  }
  for(u=0;u<8;u++)
  {
    if( (!ok(row+5*dx[u],col+5*dy[u])) && (num(row, col, u,color)==4) )
      sum++;
  }
  return sum;
}
//�������
int live3(int row,int col,int color)
{
  int u;
  int sum=0;
  for(u=0;u<8;u++)
  {
    if( ok(row-dx[u],col-dy[u]) && num(row,col,u,color)==3 && ok(row+4*dx[u],col+4*dy[u]))
      sum++;
    if(ok(row-2*dx[u],col-2*dy[u]) && ok (row+3*dx[u],col+3*dy[u])&&num(row, col,u,color)==2 && same(row, col,u,color)==1)
      sum++;
  }
  return sum;
}
//��3���
int die3(int row,int col,int color)
{
  int u;
  int sum=0;
  for(u=0;u<8;u++)
  {
    if(ok(row-dx[u],col-dy[u]) && !ok(row+4*dx[u],col+4*dy[u]) && num(row,col,u,color)==3)
      sum++;
    if(ok(row+dx[u],col+dy[u]) && !ok(row+5*dx[u],col+5*dy[u]) && num(row+dx[u],col+dy[u],u,color)==3)
      sum++;

    if(ok(row-2*dx[u],col-2*dy[u]) && !ok(row+3*dx[u],col+3*dy[u])&&num(row,col,u,color)==2&&num(row, col,-u,color)==1)
      sum++;
    if(ok(row+2*dx[u],col+2*dy[u]) && !ok(row+5*dx[u],col+5*dy[u])&&num(row,col,u,color)==1&&num(row+2*dx[u],col+2*dy[u],u,color)==2)
      sum++;


    if(ok(row-3*dx[u],col-3*dy[u]) && !ok(row+2*dx[u],col+2*dy[u]) &&same(row,col,u,color)==2&&num(row,col,u,color)==1)
      sum++;
    if(ok(row+3*dx[u],col+3*dy[u]) && !ok(row+5*dx[u],col+5*dy[u]) &&num(row,col,u,color)==2&&num(row+3*dx[u],col+3*dy[u],u,color)==2)
      sum++;

    if(ok(row-dx[u],col-dy[u])&&num(row,col,u,color)==2 &&same(row-dx[u],col-dy[u],u,color)==1)
      sum++;
    if(ok(row+dx[u],col+dy[u])&&same(row,col,u,color)==1 &&num(row+dx[u],col+dy[u],u,color)==2)
      sum++;

    if(ok(row+2*dx[u],col+2*dy[u])&&same(row,col,u,color)==1&&num(row,col,u,color)==1&&num(row+2*dx[u],col+2*dy[u],u,color)==1)
      sum++;
    if(!ok(row-dx[u],col-dy[u]) && ok(row+4*dx[u],col+4*dy[u]) && !ok(row+5*dx[u],col+5*dy[u])&&(num(row,col,u,color)==3))
      sum++;
  }
  return sum;
}
//��2���
int live2(int row,int col,int color)
{
  int u;
  int sum=0;
  for(u=0;u<8;u++)
  {
    if(ok(row+dx[u],col+dy[u])&&ok(row+4*dx[u],col+4*dy[u])&&ok(row+5*dx[u],col+5*dy[u])&&num(row+dx[u],col+dy[u],u,color)==2)
      sum++;
    if(ok(row-dx[u],col-dy[u])&&ok(row+4*dx[u],col+4*dy[u])&&ok(row+3*dx[u],col+3*dy[u])&&num(row,col,u,color)==2)
      sum++;

    if(ok(row+2*dx[u],col+2*dy[u]) && ok(row+4*dx[u],col+4*dy[u]) && num(row,col,u,color)==1&&num(row+2*dx[u],col+2*dy[u],u,color)==1)
      sum++;

    if(ok(row-2*dx[u],col-2*dy[u])&&ok(row+dx[u],col+dy[u])&& ok(row+3*dx[u],col+3*dy[u])&&num(row+dx[u],col+dy[u],u,color)==1&&same(row,col,u,color)==1)
      sum++;
   }
  for(u=0;u<4;u++)
  {
    if(ok(row-2*dx[u],col-2*dy[u]) && ok(row+2*dx[u],col+2*dy[u])&&num(row,col,u,color)==1&&same(row,col,u,color)==1)
      sum++;
  }
  return sum;
}

int ban(int row, int col,int color)//�ж����Ӻ��Ƿ�ɽ���
{
	if(overline(row, col,color) >1 || live3(row, col,color)+die3(row,col,color) > 1 || live2(row, col,color)>1)
    return 1;
  else
    return 0;
}
/*�������*/
int Calculate(int row, int col,int color)
{
	int ret = 0;
	ret=live4(row,col,color)*1000+chong4(row,col,color)*500+live3(row,col,color)*100+die3(row,col,color)*50+live2(row,col,color)*30;

	int u;
	for (u = 0; u < 8; u++)
	{
	  if(inboard(row + dx[u],col + dy[u]))
    {
      if (ChessState[row + dx[u]][col + dy[u]]!=0)
      ret++;
    }
	}
	return ret;
}

//�����¸��������꣬(i,j)����15*i+j
int NextChess(int commodle)
{
  //�����Ԫλ�������򷵻���Ԫλ��
 if (ChessState[7][7] == 0)
      return 15*7+7;
	int i, j;
	int BlackPoint,WhitePoint;
	int blacktemp =0;
	int whitetemp=0;
	int blacki,whitei;
	int blackj,whitej;
	//���������ҵ�������ߵ�����
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (!ok(i,j))  //�����������������
        continue;

      if(commodle==0 && ban(i,j,1)) //���ִ���ӣ�����ɨ�赽����λ��������
        continue;

      BlackPoint=Calculate(i,j,1);//������ӷ���
      WhitePoint=Calculate(i,j,2);//������ӷ���

			if (BlackPoint > blacktemp)
      {
        blacktemp = BlackPoint;
        blacki = i;
        blackj = j;
      }

      if (WhitePoint > whitetemp)
      {
        whitetemp = WhitePoint;
        whitei = i;
        whitej = j;
      }
		}
	}
  if(blacktemp>=whitetemp)
  {
    return 15*blacki+blackj;
  }
  else if(blacktemp<whitetemp)
  {
    return 15*whitei+whitej;
  }
}
