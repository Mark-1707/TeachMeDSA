// https://leetcode.com/problems/single-number-iii/description/

/*
    Time Complexity: O(N)
    Space Complexity: O(N)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

        int diff_bit = 1;

        while(!(diff_bit & XOR)){
            diff_bit = diff_bit << 1;
        }

        int a = 0;
        int b = 0;

        for(int& n: nums){
            if(n & diff_bit){
                a ^= n;
            }else{
                b ^= n;
            }
        }
        return {a, b};
    }
};