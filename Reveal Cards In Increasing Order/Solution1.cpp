// https://leetcode.com/problems/reveal-cards-in-increasing-order/description

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        vector<int> ans(n, 0);
        queue<int> q;

        for(int i = 0; i < n; i++) q.push(i);

        for(int& i: deck){
            int index = q.front();
            q.pop();
            ans[index] = i;
            if(!q.empty()){
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
        }

        return ans;
    }
};