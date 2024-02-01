// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        int first = 0;
        int second = 2 ;
        vector<int> subarr;
        while(second < nums.size() && first < nums.size()){

            if(nums[second] - nums[first] <=  k){
                subarr.emplace_back(nums[first]);
            }

            if(first == second){
                first = second + 1;
                second = first + 2;
            }else{
                first++;
            }
            
            if(subarr.size() == 3){
                v.emplace_back(subarr);
                subarr = vector<int>();
            }
        }

        if(v.size() * 3 == nums.size()){
            return v;
        }
        return vector<vector<int>>();
    }
};