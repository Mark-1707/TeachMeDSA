// https://leetcode.com/problems/two-sum/description/s

#include <bits/stdc++.h>
using namespace std;

// Brute Force solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums1 = nums;
        sort(nums1.begin(), nums1.end());
        vector<int> ans;
        int num1, num2;
        bool found = false;
        for(auto it = nums1.begin(); it != nums1.end(); it++){
         for(auto it1 = it+1; it1 != nums1.end(); it1++){
             if(*it + *it1 == target){
                 num1 = *it;
                 num2 = *it1;
                 found = true;
                 break;
             }
         }
         if(found) break;
        }
        bool first = true;
        bool second = true;
        for(int i=0; i < nums.size(); i++){
            if(num1 == nums[i] && first){
                ans.emplace_back(i);
                first = false;
                continue;
            }
            if(num2 == nums[i] && second){
                ans.emplace_back(i);
                second = false;
            }
        }
        return ans;
    }
};