// https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> seq;
        for(auto& it: nums){
            seq[it] = true;
        }

        // find all initials of possible sequences
        for(int i=0; i<nums.size(); i++){
            if(seq.count(nums[i]-1) > 0){
                seq[nums[i]] = false;
            }
        }

        int max = 0;
        int count = 1;
        // find the lenght of sequence
        for(int i=0; i<nums.size(); i++){
            if(seq[nums[i]] == true){
                int temp = nums[i];
                count = 1;
                while(seq.count(temp + count) > 0){
                    count++;
                }
            }
            if(max < count) max = count;
        }
        return max;
    }
};