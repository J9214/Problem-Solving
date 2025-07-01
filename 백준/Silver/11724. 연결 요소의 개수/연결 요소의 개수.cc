#include <bits/stdc++.h>
using namespace std;

void BFS(int v, vector<vector<int>> &vec, bool visited[]) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < vec[current].size(); i++) {
            int adjacent = vec[current][i];
            if (!visited[adjacent]) {
                q.push(adjacent);
                visited[adjacent] = true;
            }
        }
    }
}

int main() {
    int n, m, start, end;

    cin >> n >> m;

    // 그래프 생성
    bool *visited = new bool[n + 1]{};
    vector<vector<int>> vec(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> start >> end;
        vec[start].push_back(end);
        vec[end].push_back(start);
    }

    int components = 0; 

    // DFS
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            BFS(i, vec, visited);
            components++;
        }
    }

    cout << components;

    delete[] visited;

    return 0;
}
