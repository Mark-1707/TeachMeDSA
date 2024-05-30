// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^3)

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int count = 0;

        for(int i=0; i<arr.size()-1; i++){
            int a = 0;
            for(int j=i+1; j<arr.size(); j++){

                a ^= arr[j-1];

                int b = 0;
                for(int k=j; k<arr.size(); k++){
                    b ^= arr[k];

                    if(a == b) count++;
                }
            }
        }
        return count;
    }
};