// https://leetcode.com/problems/sum-of-subarray-minimums/

// Brute force solution (TLE)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int MOD = 1000000007;
        unsigned window = 0;
        unsigned sum = 0;
        while(window < arr.size()){
            for(unsigned i=0; i<arr.size()-window; i++){
                int min1 = INT_MAX;
                for(unsigned j=i; j <= (i+window); j++ ){
                    min1 = min(min1, arr[j]);
                }
                sum = (sum + min1) % MOD;
            }
            window++;
        }
        return sum % MOD;

    }
};