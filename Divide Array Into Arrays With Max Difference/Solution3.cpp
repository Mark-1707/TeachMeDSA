// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        vector<int> subarr;

        for(int i=0; i< nums.size(); i++){
            subarr.emplace_back(nums[i]);
            
            if(subarr.size() == 3){
                if(subarr[2] - subarr[0] > k) return {};
                v.emplace_back(subarr);
                subarr.clear();
            }
        }

        return v;
    }
};