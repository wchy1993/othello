#include"Othello.h"
#include"player.h"
#include"AI.h"

//if you can put the piece here 
Player ply;

bool Othello::PlayJudge(int row, int col, int drow, int dcol ,int color )
{
	if (board[row][col] != 0)return false;
	int trow = row, tcol = col;
	
	while (trow + drow >= 0 && trow + drow < size && tcol + dcol >= 0 && tcol + dcol < size && board[trow + drow][tcol + dcol] == ply.GetEnemyColor(color))  //color 1 =black   2 =white 
	{
		trow += drow, tcol += dcol;
		//cout << trow << trow;
	}

	if (trow == row && tcol == col)
	{
		return false;
	}
	if (trow + drow >= 0 && trow + drow < size && tcol + dcol >= 0 && tcol + dcol < size && board[trow + drow][tcol + dcol] == color)
	{
		return true;
	}
	return false;
	
}

//if you can put the piece here 
bool Othello::Isok(int row, int col, int color)
{
	if (board[row][col])
	{
		return false;
	}
	for (int i = 0; i < size; i++)
	{
			int a = drow[i] ;
			int b = dcol[i] ;
			if (PlayJudge(row, col, a, b, color))
			{
				return true;
			}
	}
	return false;
}
//count the number of pieces 
int Othello::GetNum(int color)
{
	int s = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == color)
			{
				s++;
			}
		}
	return s;
}
// the othello board 
void Othello::DrawBoard(int color)
{
	system("cls");
	//char  ch = 'A';
	for (int i = 0; i < size; i++)
	{
		if (!i)
		{
			cout << "    ";
			for (int j = 0; j < size; j++)cout << char('A' + j) << "    ";
			cout << endl;
		}
		cout << i + 1 << "  ";
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == 2)
			{
				cout << "›";
			}
			else if (board[i][j] == 1)
			{
				cout << "œ";
			}

			else if (Isok(i, j,  color))
			{
				cout << "H";
			}
			else
			{
				cout << " .";
			}
			cout << "   ";
		}
		cout << endl << endl;
	}
	cout << "Black:" << GetNum(1) << "      WhiteF" << GetNum(2) << "\n";
	if ( color == 1)
	{
		cout << "Black turn\n";
		//cout <<  color;
	}
	else
	{
		cout << "White turn\n";
	}
	cout << "choice:";
	for (int i = 0; i < size; i++)for (int j = 0; j < size; j++)if (Isok(i, j, color))
		cout << "  " << char('1' + i) << char('A' + j)<< i << j;
		
}


// init board 
void Othello::Init(int color)
{
	board[(size - 2) / 2][(size - 2) / 2] = board[size / 2][size / 2] = 2;
	board[(size - 2) / 2][size / 2] = board[size / 2][(size - 2) / 2] = 1;
	DrawBoard(color);

	//player[0] = new Player();
	//player[1] = new Ai();
	//playerIndex = 0;
}

//the
bool Othello::Win()
{
	
	cout << "\n game over \n";
	if (GetNum(1) < GetNum(2))
	{
		cout << "white win";

	}
	else if (GetNum(1) > GetNum(2))
	{
		cout << "black win";

	}
	else
	{
		cout << "planishing";
	}
	return true;
}

void Othello::Turn(int trow, int tcol, int drow, int dcol,int color)
{
	if (!PlayJudge(trow, tcol, drow, dcol,color))return;
	while (trow + drow >= 0 && trow + drow < size && tcol + dcol >= 0 && tcol + dcol < size && board[trow + drow][tcol + dcol] ==  ply.GetEnemyColor( color))
	{
		board[trow + drow][tcol + dcol] =  color;
		trow += drow, tcol += dcol;
	}
}

void run()
{

}

