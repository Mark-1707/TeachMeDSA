// https://leetcode.com/problems/score-after-flipping-matrix/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i=0; i<rows; i++){
            if(grid[i][0] == 0){
                for(int j=0; j<cols; j++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        for(int j=0; j<cols; j++){
            int z = 0;
            int o = 0;

            for(int i=0; i<rows; i++){
                if(grid[i][j] == 0) z++;
                else o++;
            }

            if(z > o){
                for(int i=0; i<rows; i++){
                    grid[i][j] = !grid[i][j];
                }
            }

        }

        int sum = 0;
        for(int i=0; i<rows; i++){
            int num = 0;
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    num += pow(2, cols - 1 - j);
                }
            }
            sum += num;
        }
        return sum;
    }
};