#include"ChessBoard.h"
#include"Move.h"
int main()
{
	ChessBoard board;
	board.test_print();
	Move move(board.getBoard());
	
	return 0;
}