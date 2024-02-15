// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity O(n)

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<long> preSum(nums.size(), 0);
        preSum[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            preSum[i] = preSum[i-1] + nums[i];
        }

        for(int i=nums.size()-1; i>= 2; i--){
            if(preSum[i-1] > nums[i]) return preSum[i];
        }

        return -1;
    }
};