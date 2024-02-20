// https://leetcode.com/problems/missing-number/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = (size * (size + 1))/2;
        int arrSum = 0;
        for(int i=0; i < size; i++){
            arrSum += nums[i];
        }
        return sum - arrSum;
    }
};
