// https://leetcode.com/problems/product-of-array-except-self/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int pref[len], suff[len];
        pref[0] = 1;
        suff[len-1] = 1;
        
        // prefix product
        for(int i=1; i<len; i++){
            pref[i] = pref[i-1] * nums[i-1];
        }

        // suffix product
        for(int i=len-2; i>=0; i--){
            suff[i] = suff[i+1] * nums[i+1];
        }

        vector<int> ans;

        // ans
        for(int i=0; i<len; i++){
            ans.emplace_back(pref[i]*suff[i]);
        }

        return ans;
    }
};
