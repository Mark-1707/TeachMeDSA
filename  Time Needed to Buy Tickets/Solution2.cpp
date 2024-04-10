// https://leetcode.com/problems/time-needed-to-buy-tickets/

// Simulation

// SC = O(1)
// TC = O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sum = 0;
        for(int i=0; i<tickets.size(); i++){
            if(i <= k){
                if(tickets[i] >= tickets[k]) sum += tickets[k];
                else sum += tickets[i];
            }else{
                if(tickets[i] >= tickets[k]) sum += tickets[k] - 1;
                else sum += tickets[i];
            }
        }
        return sum;
    }
};