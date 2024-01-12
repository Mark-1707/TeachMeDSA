// https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int max_left = 0;
        int max_right = 0;
        int len = height.size();
        int left_arr[len];
        int right_arr[len];
        for(int i = 0; i<len; i++){
            max_left = max(max_left, height[i]);
            left_arr[i] = max_left;

            max_right = max(max_right, height[len -1 -i]);
            right_arr[len-1-i] = max_right;
        }

        int ans = 0;
        for(int i=0; i<len; i++){
            int sum = min(left_arr[i], right_arr[i]) - height[i];
            if(sum <= 0) continue;
            ans = ans + sum;
        }
        return ans;
    }
};