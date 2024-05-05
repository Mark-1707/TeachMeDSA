// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> set;
        int ans = -1;
        for(int& n: nums){
            if(n > 0){
                if(set.find(0-n) != set.end()){
                    ans = max(ans, n);
                }
            }else{
                if(set.find(0-n) != set.end()){
                    ans = max(ans, abs(n));
                }
            }
            set.insert(n);
        }
        
        return ans;
    }
};