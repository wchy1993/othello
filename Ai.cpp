#include "Ai.h"
#include<ctime>


Othello othello;
void  Ai::PutStone(int color)
{
	for (int i = 0; i < size; i++)for (int j = 0; j < size; j++)if (othello.Isok(i, j, color))
	{
		Aiboxi[count] = i;
		Aiboxj[count] = j;
		count = count + 1;
	}
	srand(int(time(0)));
	int N = rand() % count;
	cout << N;
	int  row = Aiboxi[N];
	int  col = Aiboxj[N];
	//initialize the aibox and count 
	for (int i = 0; i < 8; i++)
	{
		Aiboxi[i] = 0;
		Aiboxj[i] = 0;
	}
	count = 0;
	for (int i = 0; i < size; i++)
	{
		othello.Turn(row, col, othello.drow[i], othello.dcol[i], color);
	}
	othello.board[row][col] = color;
	color = GetEnemyColor(color);
	othello.DrawBoard(color);
}