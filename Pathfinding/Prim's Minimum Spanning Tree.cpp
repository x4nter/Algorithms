//does not work yet
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void prim(vector<vector<int>> graph, int startNode){
    int length = graph.size();
    vector<int> key(length, INT_MAX), parent(length), unvisited;
    for(int i = 0; i < length; i++) unvisited.push_back(i);
    key[startNode] = 0;
    while(!unvisited.empty()){
        int curNode = 0, min = INT_MAX, curNodeIndex;
        for(int i = 0; i < unvisited.size(); i++){
            if(key[unvisited[i]] < min){
                min = key[unvisited[i]];
                curNode = unvisited[i];
                curNodeIndex = i;
            }
        }
        unvisited.erase(unvisited.begin() + curNodeIndex);
        for(int i = 0; i < length; i++){
            if(graph[curNode][i] && graph[curNode][i] < key[i]){
                parent[i] = curNode;
                key[i] = graph[curNode][i];
            }
        }
    }
    for(int i = 1; i < length; i++)
        cout << parent[i] << " - " << i << " = " << key[i] << endl;
}

int main(){
    vector<vector<int>> matrix = {{0,  0, 2, 0, 5,  0, 0, 0},
                                  {0,  0, 0, 4, 4, 10, 0, 0},
                                  {2,  0, 0, 8, 0,  0, 0, 5},
                                  {0,  4, 8, 0, 0,  5, 2, 0},
                                  {5,  4, 0, 0, 0,  0, 3, 0},
                                  {0, 10, 0, 5, 0,  0, 0, 7},
                                  {0,  0, 0, 2, 3,  0, 0, 0},
                                  {0,  0, 5, 0, 0,  7, 0, 0}};
    prim(matrix, 0);
    return 0;
}
