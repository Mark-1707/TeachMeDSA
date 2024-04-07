#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[]){

    vector<bool> visited(adj->size(), false);
    vector<int> ans;
    queue<int> q;
    q.push(0);

    visited[0] = true;
    while(!q.empty()){
        int node = q.front();
        ans.emplace_back(node);
        q.pop();
        for(int& it: adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> adj[20];
    adj[0] = {1,2,3};
    adj[2] = {0,4};
    adj[1] = {0};

    for(int& n: bfs(adj)){
        cout<<n<<endl;
    }
}