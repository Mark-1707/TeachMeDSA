// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        unordered_map<int, int> map;
        int maxNum = INT_MIN;

        for(int& n: nums){
            map[n]++;
            maxNum = max(maxNum, n);
        }


        for(int i=0; i <= maxNum; i++){
            int count = 0;
            for(const auto& p: map){
                if(p.first >= i){
                    count += p.second;
                }
                if(count > i) break;
            }
            if(count == i) return i;
        }

        return -1;
        
    }
};