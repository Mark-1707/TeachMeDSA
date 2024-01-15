// https://leetcode.com/problems/search-a-2d-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i=0; i<matrix.size(); i++){
            int l = 0;
            int r = matrix[i].size()-1;
            int mid;
            while(l <= r){
                mid = l + (r - l + 1)/2;
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] < target) l = mid+1;
                else r = mid-1;
            }
        }
        return false;

    }
};