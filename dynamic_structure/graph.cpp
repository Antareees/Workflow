#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void bfs(vector<vector<int>> &graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void dfs(vector<vector<int>> &graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;

    visited[start] = true;
    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 7;
    vector<vector<int>> graph(n);

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(5);
    graph[6].push_back(5);

    graph[1].push_back(0);
    graph[2].push_back(0);
    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[4].push_back(2);
    graph[4].push_back(3);
    graph[5].push_back(3);
    graph[5].push_back(4);
    graph[5].push_back(6);

    cout << "obhod v shiriny: " << endl;
    bfs(graph, 0);

    cout << endl << "obhod v glubinu: " << endl;
    dfs(graph, 0);

    return 0;
}