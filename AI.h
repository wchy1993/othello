#pragma once
#include"Othello.h"
#include"player.h"
#ifndef _AI_H
#define _AI_H

class Ai : public PlayerBase
{
public:
	void  PutStone(int color) override;
private:
	int count=0; 
	int Aiboxi[20];
	int Aiboxj[20];
};

#endif  


