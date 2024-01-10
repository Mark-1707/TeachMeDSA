// https://leetcode.com/problems/3sum/submissions/1142752944/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> result_set;
        vector<vector<int>> result;

        for(int i=0; i<nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) {
                    result_set.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }else if(sum > target) k--;
                else if(sum < target ) j++;
            }
        }

        for(auto& it: result_set){
            result.push_back(it);
        }
        return result;
    }
};