// https://leetcode.com/problems/sum-of-all-subset-xor-totals

#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
    vector<int> set;
    int ans = 0;
    void findAns(int i,  vector<int>& nums){

        if(i >= nums.size()){
            int xo = 0;
            for(int& n: set){
                xo ^ n;
            }
            ans += xo;
            return;
        }

        set.push_back(nums[i]);

        findAns(i + 1, nums);

        set.pop_back();

        findAns(i + 1, nums);

    }

public:
    int subsetXORSum(vector<int>& nums) {
        findAns(0, nums);
        return ans;
    }
};