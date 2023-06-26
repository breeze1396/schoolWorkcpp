#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

const int MAXN = 1000;
const int INF = 10000000;
using PII = pair<int, int> ;

int n; // 顶点数
int m; // 边数
vector<PII> graph[MAXN]; // 邻接表存储图
bool visited[MAXN]; // 标记顶点是否已经加入生成树

vector<pair<int, int>> prim(int n) {
    priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> q;
    q.push({ 0, {0, 0} });
    vector<bool> visited(n);
    vector<pair<int, int>> mst;
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        int w = t.first, u = t.second.first, v = t.second.second;
        if (visited[v]) continue;
        visited[v] = true;
        if (u != v) mst.push_back({ u, v });
        for (auto& e : graph[v]) {
            if (!visited[e.first]) {
                q.push({ e.second, {v, e.first} });
            }
        }
    }
    return mst;
}


void print_graph(int n = 0) {
    for (int i = 0; i < n; i++) {
        for (auto e : graph[i]) {
            int j = e.first, w = e.second;
            if (i < j) {
                cout << i << " " << j << " " << w << endl;
            }
        }
    }
}

int main() {
    int n = 5; 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int w = rand() % 10 + 1;
            graph[i].push_back({ j, w });
            graph[j].push_back({ i, w });
        }
    }

    print_graph(n);
    cout << "---------------------" << endl;

    vector<pair<int, int>>ans = prim(n);
    for (auto& a : ans)
        cout << setw(3) << a.first << ' ' << a.second << endl;

    return 0;
}
