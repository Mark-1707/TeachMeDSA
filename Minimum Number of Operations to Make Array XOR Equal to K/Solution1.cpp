// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = 0;
        for(int it: nums) finalXor ^= it;
        int one = 0;
        while(k > 0 || finalXor > 0){
            if(k % 2 != finalXor % 2){
                one++;
            }
            k /= 2;
            finalXor /= 2;
        }
        return one;
    }
};