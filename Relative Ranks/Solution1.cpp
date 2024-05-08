// https://leetcode.com/problems/relative-ranks/description

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> pos;

        for(int i=0; i < score.size(); i++){
            pos.push_back({i, score[i]});
        }

        sort(pos.begin(), pos.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second > p2.second;
        });

        vector<string> ans(score.size());

        for(int i=0; i<score.size(); i++){
            if(i+1 == 1){
                ans[pos[i].first] = "Gold Medal";
            }else if(i+1 == 2){
                ans[pos[i].first] = "Silver Medal";
            }else if(i+1 == 3){
                ans[pos[i].first] = "Bronze Medal";
            }else{
                ans[pos[i].first] = to_string(i+1);
            }
        }
        return ans;
    }
};