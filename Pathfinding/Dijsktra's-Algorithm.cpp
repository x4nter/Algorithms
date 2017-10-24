#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool allTrue(vector<bool>* v){
    bool b;
    for(int i = 0; i < v->size(); i++){
        if(!&v[i]){
            b = false;
            break;
        }
    }
    return b;
}

vector<int> dijkstra(vector<vector<int>> graph, int srcNode){
    int length = graph.size();
    vector<int> dist(length, INT_MAX);
    vector<bool> visited(length, false);
    dist[srcNode] = 0;
    visited[srcNode] = true;
    while(!allTrue(&visited)){
        int curNode;
        for(int i = 0; i < length; i++){
            int min = INT_MAX;
            if(dist[i] < min && !visited[i]){
                min = dist[i];
                curNode = i;
            }
        }
        visited[curNode] = true;
        for(int i = 0; i < length; i++){
            if(!visited[i] && graph[curNode][i] && graph[curNode][i] + dist[curNode] < dist[i])
                dist[i] = dist[curNode] + graph[curNode][i];
        }
    }
    return dist;
}

int main() {
    vector<vector<int>> matrix = {{0,  0, 2, 0, 5,  0, 0, 0},
                                  {0,  0, 0, 4, 4, 10, 0, 0},
                                  {2,  0, 0, 8, 0,  0, 0, 5},
                                  {0,  4, 8, 0, 0,  5, 2, 0},
                                  {5,  4, 0, 0, 0,  0, 3, 0},
                                  {0, 10, 0, 5, 0,  0, 0, 7},
                                  {0,  0, 0, 2, 3,  0, 0, 0},
                                  {0,  0, 5, 0, 0,  7, 0, 0}};
    vector<int> distFromSrc = dijkstra(matrix, 0);
    for(int i = 0; i < distFromSrc.size(); i++)
        cout << i << " : " << distFromSrc[i] << endl;
    return 0;
}
