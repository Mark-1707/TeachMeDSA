// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;

        for(int& it: target) map1[it]++;
        for(int& it: arr) map2[it]++;

        for(int& it: target) if(map1[it] != map2[it]) return false;
        return true;
    }
};