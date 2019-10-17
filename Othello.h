#include<iostream>
#include <stdlib.h>
#include"player.h"
using namespace std;
#ifndef  _OTHELLO_H
#define _OTHELLO_H
#define size  8 



class Othello
{
public:
	void Init( int color);
	bool Win();
	//void Run();
	int board[size][size] = { 0 };  //ches board 
	const int drow[8] = { 0, 0, 1, 1, 1, -1, -1, -1 }, dcol[8] = { 1, -1, 0, 1, -1, 0, 1, -1 }; //direction 8 
	void Turn(int trow, int tcol, int drow, int dcol, int color);
	void DrawBoard(int color);
	bool Isok(int row, int col, int color);
	bool PlayJudge(int row, int col, int drow, int dcol,int color);
	
protected :
	int GetNum(int color);
	//PlayerBase* player[2];
	//int playerIndex;
};
#endif  