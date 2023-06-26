#pragma once
#include<vector>
#include<iostream>
using std::vector;
class ChessBoard
{
public:
	ChessBoard();
	void test_print();
	vector<vector<int>>& getBoard() { return m_board; }
private:
	void initialization();
	vector<vector<int>> m_board;
};

