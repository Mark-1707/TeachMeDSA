// https://leetcode.com/problems/find-the-pivot-integer/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        vector<int> preSum(n);

        int sum1 = 1;
        int sum2 = (n * (n + 1))/2;

        preSum[0] = 1;

        for(int i=1; i<n; i++){
            preSum[i] = sum1 + i + 1;
            sum1 = preSum[i];
            if(sum2 - preSum[i] == preSum[i-1]) return i+1;
        }

        return -1;
    }
};