// https://leetcode.com/problems/find-the-duplicate-number/description/


// floyd warshall algorithm

/*
    time complexity: O(n)
    space complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = 0;
        int fast = 0;

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast) break;
        }

        int slow2 = 0;
        while(true){
            slow2 = nums[slow2];
            slow = nums[slow];

            if(slow == slow2) return slow;
        }

        return 0;
    }
};