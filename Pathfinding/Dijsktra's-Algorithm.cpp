#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void removeNode(vector<int>* v, int value){
    vector<int>::iterator it = find(v->begin(), v->end(), value);
    v->erase(it);
}

void dijsktra(vector<vector<int>> graph, int srcNode){
    int length = graph.size();
    vector<int> distFromSrc(length, INT_MAX), queue;
    distFromSrc[srcNode] = 0;
    for(int i = 0; i < length; i++)
        queue.push_back(i);
    while(!queue.empty()){
        int curNode;
        for(int j = 0; j < queue.size(); j++){
            int min = INT_MAX;
            if(distFromSrc[j] < min){
                min = distFromSrc[j];
                curNode = j;
            }
        }
        //removeNode(&queue, curNode);
        vector<int>::iterator it = find(queue.begin(), queue.end(), curNode);
        queue.erase(it);
        for(int j = 0; j < queue.size(); j++){
            if(graph[curNode][j] && distFromSrc[curNode] + graph[curNode][j] < distFromSrc[j])
                distFromSrc[j] = distFromSrc[curNode] + graph[curNode][j];
        }
    }
    for(int i = 0; i < distFromSrc.size(); i++)
        cout << i << " : " << distFromSrc[i] << endl;
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
    dijsktra(matrix, 0);
    return 0;
}
