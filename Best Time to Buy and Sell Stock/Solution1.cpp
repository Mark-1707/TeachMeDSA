// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int l = 0;
        int r = 1;
        
        while(l <= r && r < prices.size()){
            ans = max(ans, prices[r] - prices[l]);
            if(prices[r] < prices[l]){
                l = r;
            }else{
                r += 1;
            }
        }
        return ans;
    }
};