// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int& n: nums){
            if(nums[abs(n) - 1] < 0) ans.emplace_back(abs(n));
            else nums[abs(n) - 1] = 0 - nums[abs(n) - 1];
        }
        return ans;
    }
};