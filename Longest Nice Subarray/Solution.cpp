// https://leetcode.com/problems/longest-nice-subarray/description

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 0;
        int l = 0;
        int cur = 0;

        for(int r = 0; r < nums.size(); r++) {
            while(cur & nums[r]) {
                cur ^= nums[l];
                l += 1;
            }
            res = max(res, r - l + 1);
            cur |= nums[r];
        }
        return res;
    }
};