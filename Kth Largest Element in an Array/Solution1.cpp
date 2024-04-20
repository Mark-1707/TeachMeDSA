// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int& it: nums) q.push(it);

        while(q.size() > nums.size() - k + 1) q.pop();

        return q.top();
    }
};