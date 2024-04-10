// https://leetcode.com/problems/time-needed-to-buy-tickets/

// Simulation

// SC = O(n)
// TC = O(max(tickets)^2)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        for(int i=0; i<tickets.size(); i++){
            q.push(make_pair(tickets[i], i));
        }
        
        int time = 0;
        while(true){
            if(q.front().first){
                time++;
                pair<int, int> p = make_pair(--q.front().first, q.front().second);
                cout<<p.first<<endl;
                if(p.first == 0 && p.second == k) return time;
                q.pop();
                if(p.first) q.push(p);
            }
        }
        return time;
    }
};