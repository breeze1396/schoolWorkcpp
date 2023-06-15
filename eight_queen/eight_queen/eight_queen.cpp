#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> generateBoard(vector<int>& queens, int n) {
	auto board = vector<int>();
	for (int i = 0; i < n; i++) {
		int row = 0;
			//string(n, '.');
		row[queens[i]] = 1;
		board.push_back(row);
	}
	return board;
}

void backtrack(vector<vector<int>>& solutions, vector<int>& queens, int n, int row, unordered_set<int>& columns,
	unordered_set<int>& diagonals1, unordered_set<int>& diagonals2)
{
	if (row == n) {
		vector<int> board = generateBoard(queens, n);
		solutions.push_back(board);
	}
	else
	{
		for (int i = 0; i < n; i++) {
			if (columns.find(i) != columns.end()) {
				continue;
			}
			int diagonal1 = row - i;
			if (diagonals1.find(diagonal1) != diagonals1.end()) {
				continue;
			}
			int diagonal2 = row + i;
			if (diagonals2.find(diagonal2) != diagonals2.end()) {
				continue;
			}
			queens[row] = i;
			columns.insert(i);
			diagonals1.insert(diagonal1);
			diagonals2.insert(diagonal2);
			backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
			queens[row] = -1;
			columns.erase(i);
			diagonals1.erase(diagonal1);
			diagonals2.erase(diagonal2);
		}
	}
}

vector<vector<int>> solveNQueens(int n)
{
	auto solutions = vector<vector<int>>();
	auto queens = vector<int>(n, -1);
	auto columns = unordered_set<int>();
	auto diagonals1 = unordered_set<int>();
	auto diagonals2 = unordered_set<int>();
	backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
	return solutions;
}





int main()
{
	auto ans = solveNQueens(21);
	//for (auto& a : ans)
	//{
	//	for (auto& c : a)
	//		cout << c << endl;
	//	cout << "--------------------------------" << endl;
	//}
	cout << ans.size() << endl;
}
