#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int, int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 当前位置四个方向的偏移量
vector<pair<int, int>> path; // 存找到的路径
vector<vector<int>> maze = { 
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };


void mark(vector<vector<int>>& maze, pair<int, int> pos) { // 给迷宫maze的位置pos标"2"表示“倒过了”
    maze[pos.first][pos.second] = 2;
}

bool passable(vector<vector<int>>& maze, pair<int, int> pos) { // 检查迷宫maze的位置pos是否可通行
    return maze[pos.first][pos.second] == 0;
}

bool find_path_recursion(vector<vector<int>>& maze, pair<int, int> pos, pair<int, int> end) {
    mark(maze, pos);
    if (pos == end) {
        cout <<"(" << pos.first << " " << pos.second << ") ";
        path.push_back(pos);
        return true;
    }
    for (int i = 0; i < 4; i++) { // 否则按四个方向顺序检查
        pair<int, int> nextp = { pos.first + dirs[i].first, pos.second + dirs[i].second };
        // 考虑下一个可能方向
        if (passable(maze, nextp)) { // 不可行的相邻位置不管
            if (find_path_recursion(maze, nextp, end)) { // 如果从nextp可达出口，输出这个位置，成功结束
                cout << "(" << pos.first << " " << pos.second << ") ";
                path.push_back(pos);
                return true;
            }
        }
    }
    return false;
}

/*
\033 是 ASCII 转义字符。它用于开始一个转义序列，可以用来更改终端中文本的颜色和其他属性。
在这段代码中，\033 后面跟着 [ 和一系列用 ; 分隔的数字，这些数字代表不同的属性。
0 会重置所有属性为默认值，
31 会将前景色设置为红色，
32 会将前景色设置为绿色，
34 会将前景色设置为蓝色，
40 会将背景色设置为黑色。
序列末尾的 m 表示这是一个“选择图形再现”（SGR）序列，用于设置显示属性，如颜色和文本样式。*/
void see_path(vector<vector<int>>& maze, vector<pair<int, int>> path) { // 使寻找到的路径可视化
    for (int i = 0; i < path.size(); i++) {
        if (i == 0) {
            maze[path[i].first][path[i].second] = 'E';
        }
        else if (i == path.size() - 1) {
            maze[path[i].first][path[i].second] = 'S';
        }
        else {
            maze[path[i].first][path[i].second] = 3;
        }
    }
    cout << "\n";
    for (auto r : maze) {
        for (auto c : r) {
            if (c == 3) {
                cout  << "\033[0;300m" << "*" << " " << '\033' << "[0m";
            }
            else if (c == 'S' || c == 'E') {
                cout <<  "\033[0;34m" << char(c) << " " << '\033' << "[0m";
            }
            else if (c == 2) {
                cout  << "\033[0;32m" << "#" << " " << '\033' << "[0m";
            }
            else if (c == 1) {
                cout  << "\033[1;43m" << "  " << '\033' << "[0m";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void print_path(pair<int, int> end, pair<int, int> start, pair<int, int> pos, stack<pair<pair<int, int>, int>> st) {

    cout << end.first << " " << end.second << endl;
    while (!st.empty()) {
        cout << st.top().first.first << " " << st.top().first.second << endl;
        maze[st.top().first.first][st.top().first.second] = 3;
        st.pop();
    }
    maze[pos.first][pos.second] = 3;
    maze[start.first][start.second] = 'S';
    maze[end.first][end.second] = 'E';
}

void find_path_back(vector<vector<int>>& maze, pair<int, int> start, pair<int, int> end) {
    if (start == end) {
        cout << start.first << " " << start.second << endl;
        return;
    }
    stack<pair<pair<int, int>, int>> st;
    mark(maze, start);
    st.push(make_pair(start, 0));
    while (!st.empty()) {
        pair<pair<int, int>, int> temp = st.top();
        pair<int, int> pos = temp.first;
        int nxt = temp.second;
        st.pop();
        for (int i = nxt;i < 4;i++) {
            pair<int, int> nextp = { pos.first + dirs[i].first,pos.second + dirs[i].second };
            if (nextp == end) {
                print_path(end, start, pos, st);
                return;
            }
            if (passable(maze, nextp)) {
                st.push(make_pair(pos, i + 1));
                mark(maze, nextp);
                st.push(make_pair(nextp, 0));
                break;
            }
        }
    }
    cout << "找不到路径" << endl;
}


void the_way_1() {
    pair<int, int> start{ 1,1 }, end{ 8,10 };
    find_path_recursion(maze, start, end);
    see_path(maze, path);
}
void the_way_2() {
    pair<int, int> start{ 1,1 }, end{ 8,10 };
    find_path_back(maze, start, end);
    see_path(maze, path);
}


int main() {
    the_way_1();
    return 0;
}