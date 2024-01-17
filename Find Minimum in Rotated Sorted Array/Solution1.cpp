// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int min1 = 5000;
        while(l <= r ){
            int mid = (l+r) / 2;
            if(nums[mid] > nums[nums.size()-1]){
                l = mid+1;
            }else{
                r = mid - 1;
                if(r<0){
                    return nums[r+1];
                }
            }
            min1 = min(min1, nums[mid]);
        }
        return min1;
    }
};