// https://leetcode.com/problems/minimum-common-value/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int temp = 0;
        for(int i = 0; i<nums1.size(); i++){
            for(int j = temp; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]) return nums1[i];
                temp = j;
                if(nums1[i] < nums2[j]) break;
            }
            if(temp == nums2.size()) return -1;
        }
        return -1;
    }
};