#include "ChessBoard.h"
#include <iomanip>
ChessBoard::ChessBoard()
{
	m_board = vector<vector<int>> (10,vector<int>(9));
	initialization();
}

void ChessBoard::test_print()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << std::setw(4) << m_board[i][j] << ' ';
		}
		std::cout<<std::endl;
	}
}

/*
* y
* 11
* ...    横轴为x轴，y为纵轴，比如
* 2      （0，1）放马
* 1
* 0  1  2  ... 11 x
*/
void ChessBoard::initialization()
{
	//车马相似帅12345
	for (int i{ 0 }; i < 5; ++i)
	{
		m_board[0][i] = i;//红子左侧
		m_board[0][8 - static_cast<std::vector<int, std::allocator<int>>::size_type>(i)] = i;//红子左侧
		m_board[9][i] = i * 2;//黑子右侧
		m_board[9][8 - static_cast<std::vector<int, std::allocator<int>>::size_type>(i)] = i * 2;//黑子右侧
	}

	//小兵 = 7
	for (int i{ 0 }; i < 5; ++i)
	{
		m_board[3][static_cast<std::vector<int, std::allocator<int>>::size_type>(i) * 2] = 7;//黑子
		m_board[6][static_cast<std::vector<int, std::allocator<int>>::size_type>(i) * 2] = 7 * 2;  //红子
	}

	//炮 = 6
	m_board[2][1] = 6;
	m_board[7][1] = 6 * 2;
	m_board[2][7] = 6;
	m_board[7][7] = 6 * 2;
}
