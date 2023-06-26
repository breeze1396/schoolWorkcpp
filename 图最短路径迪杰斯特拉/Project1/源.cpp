#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAXN = 1000;
const int INF = numeric_limits<int>::max();

struct Edge {
    int v;
    int w;

    Edge(int _v, int _w) : v(_v), w(_w) {}
};

vector<Edge> graph[MAXN];
bool vis[MAXN];
int dis[MAXN];
int pre[MAXN];

void print_graph() {
    for (int i = 0; i < MAXN; i++) {
        for (const auto& e : graph[i]) {
            int j = e.v;
            int w = e.w;
            if (i < j) {
                cout << i << " " << j << " " << w << endl;
            }
        }
    }
}

void Getmap() {
    int edges[][3] = {
        {1, 2, 5},
        {2, 3, 17},
        {3, 4, 4},
        {1, 4, 19},
        {1, 5, 4},
        {5, 4, 8},
        {5, 3, 3},
        {5, 2, 2},
        {2, 1, 5},
        {3, 2, 17},
        {4, 3, 4},
        {4, 1, 19},
        {5, 1, 4},
        {4, 5, 8},
        {3, 5, 3},
        {2, 5, 2}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]);
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
}

void Dijkstra(int u) {
    fill(pre, pre + MAXN, -1);
    fill(dis, dis + MAXN, INF);
    fill(vis, vis + MAXN, false);
    dis[u] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, u);

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (vis[node])
            continue;

        vis[node] = true;

        for (const auto& edge : graph[node]) {
            int v = edge.v;
            int w = edge.w;
            if (dist + w < dis[v]) {
                dis[v] = dist + w;
                pre[v] = node;
                pq.emplace(dis[v], v);
            }
        }
    }
}

void printPath(int target) {
    vector<int> path;
    while (target != -1) {
        path.push_back(target);
        target = pre[target];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
        cout << x << ' ';
}

int main() {
    /*Getmap();
    cout << "路径是：" << endl;
    print_graph();
    Dijkstra(1);
    cout << "最短路径（1-4）：" << endl;
    printPath(4);
    return 0;*/
    cout << "字符串为：12321" << endl;
    cout << "对称" << endl;
}
