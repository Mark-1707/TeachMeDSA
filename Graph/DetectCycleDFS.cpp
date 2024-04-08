#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int> adj[], vector<bool>& visited, int node, int parent){

    visited[node] = true;

    for(int& it: adj[node]){
        if(!visited[it]){
            if(dfs(adj, visited, it, node)) true;
        }else{
            if(parent != it) return true;
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
            if(dfs(adj, visited, 1, -1)){
                cout<<true<<endl;
                break;
            }
        }
    }

    return 0;
}