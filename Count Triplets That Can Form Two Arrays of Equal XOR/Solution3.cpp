// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^2)

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int count = 0;

        for(int i=0; i<arr.size()-1; i++){
            int curr = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                curr ^= arr[j];
                if(curr == 0) count += j - i;
            }
        }
        return count;
    }
};