#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>

#define MAX_SIZE 20000+5
#define RED 1
#define BLUE 2

using namespace std;

int K, V, E;
vector<int> graph[MAX_SIZE];
int visited[MAX_SIZE];

void bfs(int start);
bool isBipartiteGraph();

void bfs(int start) {
	queue<int> q;
	int color = RED;

	visited[start] = color;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (visited[cur] == RED) {
			color = BLUE;
		}
		else if (visited[cur] == BLUE) {
			color = RED;
		}

		int gsize = graph[cur].size();

		for (int i = 0; i < gsize; i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				visited[next] = color;
				q.push(next);
			}
		}
	}
}

bool isBipartiteGraph() {
	for (int i = 1; i <= V; i++) {
		int gsize = graph[i].size();

		for (int j = 0; j < gsize; j++) {
			int next = graph[i][j];
			if (visited[i] == visited[next])
				return 0;
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int u, v;

	cin >> K;

	while (K--){
		cin >> V >> E;
		
		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (!visited[i])
				bfs(i);
		}

		if (isBipartiteGraph())
			cout << "YES\n";
		else
			cout << "NO\n";

		for (int i = 0; i <= V; i++)
			graph[i].clear();
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}
