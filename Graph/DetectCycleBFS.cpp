#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<int> adj[], vector<bool> visited, int node, int parent){
    queue<pair<int, int>> q;
    visited[node] = true;
    q.push(make_pair(node, parent));

    while(!q.empty()){

        node = q.front().first;
        parent = q.front().second;
        q.pop();

        for(int& adjNode: adj[node]){
            if(!visited[adjNode]){
                q.push(make_pair(adjNode, node));
                visited[adjNode] = true;
            }else{
                if(adjNode != parent) return true;
            }
        }
    }
    return false;
}

int main(){
    vector<int> adj[8];
    adj[0] = {};
    adj[1] = {2, 3};
    adj[2] = {1, 5};
    adj[3] = {4, 1, 6};
    adj[4] = {3};
    adj[5] = {2, 7};
    adj[6] = {3, 7};
    adj[7] = {5, 6};

    vector<bool> visited(8, false);

    for(int i=0; i<8; i++){
        if(!visited[i]){
            if(bfs(adj, visited, 1, -1)){
                cout<<true<<endl;
                break;
            }
        }
    }

    return 0;
}