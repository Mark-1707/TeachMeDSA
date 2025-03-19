// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] == 0) {
                res++;
                nums[i] = 1;
                if(nums[i + 1] == 0) nums[i + 1] = 1; else nums[i + 1] = 0;
                if(nums[i + 2] == 0) nums[i + 2] = 1; else nums[i + 2] = 0;
            }
        }
        if(nums[nums.size() - 1] == 0 || nums[nums.size() - 2] == 0) return -1;
        return res;
    }
};