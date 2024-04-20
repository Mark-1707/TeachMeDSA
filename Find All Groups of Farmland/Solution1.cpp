// https://leetcode.com/problems/find-all-groups-of-farmland/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
    pair<int, int>  min;
    pair<int, int>  max;
    void dfs(vector<vector<int>>& land, int i, int j, int row, int col, vector<vector<bool>>& vis){

        if(i < 0 || i >= row || j < 0 || j >= col || vis[i][j] || land[i][j] == 0){
            return;
        }

        vis[i][j] = true;

        if(i <= min.first && j <= min.second){
            min.first = i;
            min.second = j;
        }

        if(i >= max.first && j >= max.second){
            max.first = i;
            max.second = j;
        }

        dfs(land, i, j - 1, row, col, vis);
        dfs(land, i - 1, j, row, col, vis);
        dfs(land, i, j + 1, row, col, vis);
        dfs(land, i + 1, j, row, col, vis);

    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size();
        int col = land[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        vector<vector<int>> ans;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!vis[i][j]){
                    min = make_pair(INT_MAX, INT_MAX);
                    max = make_pair(INT_MIN, INT_MIN);
                    dfs(land, i, j, row, col, vis);
                    if(min.first != INT_MAX && max.first != INT_MIN){
                        ans.push_back({min.first, min.second, max.first, max.second});
                    }
                }
            }
        }
        return ans;
    }
};