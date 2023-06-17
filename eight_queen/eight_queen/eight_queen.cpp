#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

//vector<string> getPicture(vector<int>& queens, int n) {
//    auto board = vector<string>();
//    for (int i = 0; i < n; i++) {
//        string row = string(n, '.');
//        row[queens[i]] = '1';
//        board.push_back(row);
//    }
//    return board;
//}
//
//void backtrack(vector<vector<string>>& solutions, vector<int>& queens, \
//    int n, int row, unordered_set<int>& columns,
//    unordered_set<int>& diagonals1, unordered_set<int>& diagonals2)
//{
//    if (row == n) {
//        vector<string> board = getPicture(queens, n);
//        solutions.push_back(board);
//    }
//    else
//    {
//        for (int i = 0; i < n; i++) {
//            if (columns.find(i) != columns.end()) {
//                continue;
//            }
//            int diagonal1 = row - i;
//            if (diagonals1.find(diagonal1) != diagonals1.end()) {
//                continue;
//            }
//            int diagonal2 = row + i;
//            if (diagonals2.find(diagonal2) != diagonals2.end()) {
//                continue;
//            }
//            queens[row] = i;
//            columns.insert(i);
//            diagonals1.insert(diagonal1);
//            diagonals2.insert(diagonal2);
//            backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
//            queens[row] = -1;
//            columns.erase(i);
//            diagonals1.erase(diagonal1);
//            diagonals2.erase(diagonal2);
//        }
//    }
//}
//
//vector<vector<string>> solveNQueens(int n)
//{
//    vector<vector<string>> solutions{ };
//    vector<int> queens(n, -1);
//    unordered_set<int> columns{ };
//    unordered_set<int> diagonals1{ };
//    unordered_set<int> diagonals2{ };
//    backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
//    return solutions;
//}
//
//
//
//int main()
//{
//	auto ans = solveNQueens(8);
//	for (auto& a : ans)
//	{
//		for (auto& c : a)
//		{
//				cout << c << endl;
//		}
//			
//		cout << "--------------------------------" << endl;
//	}
//	cout << "一共有方法：" << ans.size() << endl;
//
//    return 0;
//}

class eightQueen
{
public:
	eightQueen(int n)
	{
		backtrack(1);
	}
	int getNum() { return num; }
private:
	void backtrack(int k)
	{
		if (k > n)//找到解
		{
			for (int i = 1; i <= 8; i++)
			{
				cout << a[i];
			}
			cout << endl;
			num++;
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				a[k] = i;
				if (check(a, k) == 1)
				{
					backtrack(k + 1);
				}
			}
		}

	}
	bool check(int a[], int n)
	{//多次被调用，只需一重循环 
		for (int i = 1; i <= n - 1; i++)
		{
			if ((abs(a[i] - a[n]) == n - i) || (a[i] == a[n]))
				//如果当前位置的斜上方或者斜上方有皇后，或者同一列有皇后返回false
				return false;
		}
		return true;
	}
	int a[100], n = 8, num = 0;

};

int main()
{

	eightQueen a(10);
	cout << "共有方法： " << a.getNum() << endl;
	return 0;
}

