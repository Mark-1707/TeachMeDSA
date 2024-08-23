
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> v(10000000, 0);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                v[abs(nums[i] - nums[j])]++;
            }
        }
        
        int sum = 0;
        for(int i=0; i < v.size(); i++){
            sum += v[i];

            if(sum >= k) return i;
        }
        return 0;
    }
};