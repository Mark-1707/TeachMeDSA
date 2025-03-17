// https://leetcode.com/problems/divide-array-into-equal-pairs/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> map;

        for(const int& n: nums) map[n]++;

        for(const pair<int, int>& m: map) {
            if(m.second % 2 != 0) return false;
        }

        return true;
    }
};