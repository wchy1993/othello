#pragma once
#include"Othello.h"
#ifndef  _PLAYER_H
#define _PLAYER_H
#define size  8 

class PlayerBase
{
public:
	int GetEnemyColor(int color)  // change color  1 = black 2 = white 
	{
		color = 3 - color;
		return color;
	}
	virtual void PutStone(int color) {  };
};

class Player :public PlayerBase
{
public:
	//int color = 1;  //color  1 = black ,2 =white
	void PutStone(int color) override;

};

#endif 


