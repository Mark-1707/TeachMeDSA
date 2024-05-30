// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^4)

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int count = 0;

        for(int i=0; i<arr.size()-1; i++){
            for(int j=i+1; j<arr.size(); j++){
                int a = 0;
                for(int m=i; m < j; m++){
                    a ^= arr[m];
                }
                for(int k=j; k<arr.size(); k++){
                    int b = 0;
                    for(int n = j; n<=k; n++){
                        b ^= arr[n];
                    }
                    if(a == b) count++;
                }
            }
        }
        return count;
    }
};