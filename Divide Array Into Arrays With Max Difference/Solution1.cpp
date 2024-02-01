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
        while(second < nums.size() && first < nums.size() - 2){
            vector<int> subarr;
            if((nums[second] - nums[first]) <= k){
                while(first < second + 1){
                    subarr.emplace_back(nums[first]);
                    first++;
                }
                cout<<first<<endl;
                second = first +  2;
            }else{
                first++;
                second = first + 2;
            }
            if(subarr.size() == 3) v.emplace_back(subarr);
        }
        if(v.size() * 3 == nums.size()){
            return v;
        }
        return vector<vector<int>>();
    }
};