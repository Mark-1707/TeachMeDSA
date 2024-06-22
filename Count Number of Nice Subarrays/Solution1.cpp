// https://leetcode.com/problems/count-number-of-nice-subarrays/description

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0;
        int m = 0;
        int len = nums.size();
        int odd = 0;
        int ans = 0;
        
        for(int r = 0; r < len; r++){
            if(nums[r] % 2 != 0) odd++;

            while(odd > k){
                if(nums[l] % 2 != 0) odd--;
                l++;
                m = l;
            }

            if(odd == k){
                while(!(nums[m] % 2)) m++;
                ans += (m - l )+ 1;
            }

        }

        return ans;
    }
};