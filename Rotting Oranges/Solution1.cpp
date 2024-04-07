// https://leetcode.com/problems/rotting-oranges/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int bfs(vector<vector<int>>& grid, int rows, int cols){
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(make_pair(i, j), 0));
                    vis[i][j] = true;
                }
            }
        }

        int tm = 0;
        while(!q.empty()){
            pair<int, int> co = q.front().first;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            int row, col;
            if(co.first > 0){
                row = co.first - 1;
                col = co.second;
                if(!vis[row][col] && grid[row][col] == 1){
                    grid[row][col] = 2;
                    q.push(make_pair(make_pair(row, col), t + 1));
                    vis[row][col] = true;
                }
            }
            
            if(co.first < rows - 1 ){
                row = co.first + 1;
                col = co.second;
                if(!vis[row][col] && grid[row][col] == 1){
                    grid[row][col] = 2;
                    q.push(make_pair(make_pair(row, col), t + 1));
                    vis[row][col] = true;
                }
            }

            if(co.second > 0){
                row = co.first;
                col = co.second - 1;
                if(!vis[row][col] && grid[row][col] == 1){
                    grid[row][col] = 2;
                    q.push(make_pair(make_pair(row, col), t + 1));
                    vis[row][col] = true;
                }
            }

            if(co.second < cols - 1){
                row = co.first;
                col = co.second + 1;
                if(!vis[row][col] && grid[row][col] == 1){
                    grid[row][col] = 2;
                    q.push(make_pair(make_pair(row, col), t + 1));
                    vis[row][col] = true;
                }
            }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return tm;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        return bfs(grid, rows, cols);
    }
};