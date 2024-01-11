// https://leetcode.com/problems/container-with-most-water/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int area = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l<r){
            area = min(height[l], height[r]) * (r-l);
            maxA = max(maxA, area);
            if(height[l]<height[r]) l++;
            else r--;
        }
        return maxA;
    }
};