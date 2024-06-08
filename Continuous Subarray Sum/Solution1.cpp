// https://leetcode.com/problems/continuous-subarray-sum/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        map[0] = -1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int r = sum % k;
            if(map.find(r) == map.end()){
                map[r] = i;
            } else if(i - map[r] > 1) return true;
        }

        return false;
    }
};
