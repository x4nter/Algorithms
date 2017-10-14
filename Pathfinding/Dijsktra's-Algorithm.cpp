//Does not work properly yet
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void dijsktra(vector<vector<int>> graph, int srcNode){
    int length = graph.size();
    vector<int> distFromSrc(length, INT_MAX);
    vector<bool> visited(length, false);
    distFromSrc[srcNode] = 0;
    for(int i = 0; i < length; i++){
        int curNode;
        for(int j = 0; j < length; j++){
            int min = INT_MAX;
            if(distFromSrc[j] < min){
                min = distFromSrc[j];
                curNode = j;
            }
        }
        visited[curNode] = true;
        for(int j = 0; j < length; j++){
            if(!visited[j] && graph[curNode][j] && distFromSrc[curNode] + graph[curNode][j] < distFromSrc[j])
                distFromSrc[j] = distFromSrc[curNode] + graph[curNode][j];
        }
    }
    for(int i = 0; i < distFromSrc.size(); i++)
        cout << i << " : " << distFromSrc[i] << endl;
}

int main(){
    int nNodes, edges;
    cin >> nNodes >> edges;
    vector<vector<int>> matrix(nNodes, vector<int>(nNodes, 0));
    for(int i = 0; i < edges; i++){
    	int from, to, dis;
    	cin >> from >> to >> dis;
        matrix[from][to] = dis;
        matrix[to][from] = dis;
    }
    dijsktra(matrix, 0);
    return 0;
}
