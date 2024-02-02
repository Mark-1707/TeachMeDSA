// https://leetcode.com/problems/sequential-digits/description

// Brute force (TLE)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=low; i<=high; i++){
            int num = i;
            bool seq = true;
            while(num>0){
                if(num%10 - 1 != (num/10)%10 && (num/10 != 0)){
                    seq = false;
                    break;
                }
                num = num/10;
            }
            if(seq) ans.emplace_back(i);
        }
        return ans;
    }
};