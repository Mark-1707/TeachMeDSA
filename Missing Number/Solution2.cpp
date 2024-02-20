// https://leetcode.com/problems/missing-number/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i= 0; i<=n; i++) ans ^= i;
        for(int i=0; i<n; i++) ans ^= nums[i];
        return ans;
    }
};