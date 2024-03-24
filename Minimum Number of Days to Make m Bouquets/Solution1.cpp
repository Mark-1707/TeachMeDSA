// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int minDay = INT_MAX;
        int maxDay = INT_MIN;
        int ans = INT_MAX;
        for(int i=0; i<bloomDay.size(); i++){
            minDay = min(minDay, bloomDay[i]);
            maxDay = max(maxDay, bloomDay[i]);
        }

        while(minDay <= maxDay){
            int mid = (minDay + maxDay) / 2;
            int flowers = 0;
            int bouquet = 0;
            for(int j=0; j<bloomDay.size(); j++){
                if(bloomDay[j] <= mid){
                    flowers += 1;
                    if(flowers == k){
                        bouquet++;
                        flowers = 0;
                    }
                }else{
                    flowers = 0;
                }
                if(bouquet == m){
                     ans = min(ans, mid);
                     maxDay = mid-1;
                     break;
                }
            }
            if(bouquet < m) minDay = mid + 1;
            else maxDay = mid - 1;
        }

        if(ans == INT_MAX) return -1;

        return ans;
    }
};