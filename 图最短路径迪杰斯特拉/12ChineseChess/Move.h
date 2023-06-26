#pragma once
#include "ChessBoard.h"
class Move
{
public:
	Move(vector<vector<int>>& board)
		: m_board(board)
	{
	}
	
private:
	vector<vector<int>>& m_board;
	
};

