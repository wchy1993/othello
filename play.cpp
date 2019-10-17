#include"Othello.h"
#include"player.h"
#include"AI.h"
#include<ctime>


//Ai ai;

Othello otl;


// Ai  randomly choose where to put the piece 
void Player::PutStone(int color) 
{
	cout << "input row(1-8)and col(A-H)" << endl;
	char x, y;
	cin >> x >> y;
	int row = x - '1', col = y - 'A';
	while (!otl.Isok(row, col, color))
	{
		cout << "ERROR!";
		cin >> x >> y;
		int row = x - '1', col = y - 'A';
		return;
	}
	for (int i = 0; i < size; i++)
	{
		otl.Turn(row, col, otl.drow[i], otl.dcol[i], color);
	}
	otl.board[row][col] = color;
	color = GetEnemyColor(color);
	otl.DrawBoard(color);
}
/*enum Color {
	None,
	White,
	Black
};*/
int GameStart()
{
	int choice;
	//Color color;
	//color = Color::None;
	cout << "input 1 or 2 (black =1  white =2 )" << endl;
	cin >> choice;
	otl.Init(choice);
	//cout << "white or black" << endl;
	return choice;
}

Ai ai;
Player play;



int  main()
{
	system("color f0");
	PlayerBase* player1 = new Player();
	PlayerBase* player2 = new Ai();
	int choice=GameStart();
	if (choice == 1)
	{
		for (int i=0;i<30;i++)
		{
			player1->PutStone (choice);
			player2->PutStone (play.GetEnemyColor(choice));
		}
		otl.Win();
		delete player1;
		delete player2;
	}
	else
	{
		for (int i = 0; i < 30; i++)
		{
			//ai.AIpiece();
			choice = play.GetEnemyColor(choice);
			player2->PutStone(choice);
			player1->PutStone(play.GetEnemyColor(choice));
		}
			//ai.AiPutPiece(choice);
		
		otl.Win();
		delete player1;
		delete player2;
	}
	system("pause>nul");
	return 0;
}