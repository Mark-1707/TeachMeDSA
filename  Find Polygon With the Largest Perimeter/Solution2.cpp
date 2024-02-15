// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n lon n)
// Space Complexity O(1)

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long max = -1;
        long long sum = nums[0];
        for(int i=0; i<nums.size()-1; i++){
            long  next = nums[i+1];
            long  peri = sum + next;
            if(sum > next && peri > max) max = peri;
            sum = next + sum;        
        }
        return max;
    }
};