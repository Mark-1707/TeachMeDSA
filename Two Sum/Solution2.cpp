// Hash Map approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;

        for(int i=0; i<nums.size(); i++){
            int comp = target - nums[i];
            if(num_map.count(comp) && num_map[comp] != i){
                return {num_map[comp], i};
            }
            num_map[nums[i]] = i;
        }
        return {};
        
    }
};