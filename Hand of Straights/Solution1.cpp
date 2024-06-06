// https://leetcode.com/problems/hand-of-straights/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int len = hand.size();
        if(len % groupSize != 0) return false;
        unordered_map<int, int> map;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int& n: hand) map[n]++;
        for(const auto& p: map) q.push(p.first);
        
        while(!q.empty()){
            int min = q.top();

            int count = 0;
            int n = min;
            while(count != groupSize){
                if(map[n]-- > 0){
                    count++;
                    if(map[n] == 0){
                        if(n == min){
                            q.pop();
                            min = q.top();
                        }
                        else return false;
                    }
                    n++;
                }else {
                    return false;
                }
            }
        }
  
        return true;
    }
};