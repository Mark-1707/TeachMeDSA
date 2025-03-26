// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        int rem = grid[0][0] % x;

        for(auto& g : grid){
            for(auto& ele : g) {
                if(ele % x != rem) return -1; 
                v.push_back(ele);
            }
        }

        sort(v.begin(), v.end());

        int mid1 = v[v.size() / 2];
        int count = 0;
        for(int i = 0; i < v.size(); i++) {
            count += abs(v[i] - mid1) / x;
        }

        return  count;
    }
};