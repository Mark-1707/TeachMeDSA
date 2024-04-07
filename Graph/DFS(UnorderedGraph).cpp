#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int i, vector<bool>& visited, vector<int>& res){

    visited[i] = true;
    res.emplace_back(i);

    for(int& it: adj[i]){
        if(!visited[it]){
            dfs(adj, it, visited, res);
        }
    }
}

int main(){
    vector<int> adj[20];
    vector<int> res;
    vector<bool> visited(20, false);
    adj[0] = {1,2,3};
    adj[2] = {0,4};
    adj[1] = {0};
    adj[4] = {2};

    dfs(adj, 4, visited, res);

    for(int& n: res){
        cout<<n<<endl;
    }
}