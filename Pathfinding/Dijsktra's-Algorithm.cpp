#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool allTrue(vector<bool>* v) {
	for (int i = 0; i < v->size(); i++) {
		if (!(v->at(i))) {
			return false;
		}
	}
	return true;
}

vector<int> dijkstra(vector<vector<int>> graph, int srcNode) {
	int length = graph.size();
	vector<int> dist(length, INT_MAX);
	vector<bool> visited(length, false);
	dist[srcNode] = 0;
	while (!allTrue(&visited)) {
		int curNode;
		for (int i = 0; i < length; i++) {
			int min = INT_MAX;
			if (dist[i] < min && !visited[i]) {
				min = dist[i];
				curNode = i;
			}
		}
		
		for (int i = 0; i < length; i++) {
			if (graph[curNode][i] && graph[curNode][i] + dist[curNode] < dist[i])
				dist[i] = dist[curNode] + graph[curNode][i];
		}
		visited[curNode] = true;
	}
	return dist;
}

int main() {
	vector<vector<int>> matrix = {
		{0, 4, 1, 0},
		{4, 0, 1, 1},
		{1, 1, 0, 4},
		{0, 1, 4, 0}
	};
	vector<int> distFromSrc = dijkstra(matrix, 0);
	for (int i = 0; i < distFromSrc.size(); i++)
		cout << i << " : " << distFromSrc[i] << endl;
	return 0;
}
