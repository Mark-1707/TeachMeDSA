// https://leetcode.com/problems/find-the-duplicate-number/description/


/*
    time complexity: O(n)
    space complexity: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int& n: nums){
            if(set.find(n) != set.end()) return n;
            set.insert(n);
        }

        return 0;
    }
};