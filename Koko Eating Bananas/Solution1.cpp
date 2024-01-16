// https://leetcode.com/problems/koko-eating-bananas/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int l = 1;
         int r = *max_element(piles.begin(), piles.end());
         int res = r;

         while(l <= r){
             int time = 0;
             int mid = (l+r)/2;
             for(auto& i: piles){
                 time += ceil(static_cast<double>(i)/mid);
                 if(time > h) {
                    l = mid+1;
                    break;
                 }
             }
             if(time <= h){
                 res = min(res, mid);
                 r = mid - 1;
             }
         }

        return res;
    }
};