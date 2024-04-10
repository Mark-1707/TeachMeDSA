// https://leetcode.com/problems/last-stone-weight/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        while(q.size() != 1 && !q.empty()){
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();

            if(x == y) continue;
            else q.push(y-x);
        }

        return q.empty() ? 0 : q.top();
    }
};