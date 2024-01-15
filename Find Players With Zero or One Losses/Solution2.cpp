// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, pair<int, int>> records;

        for(auto& match: matches){
            records[match[0]] = make_pair(++records[match[0]].first, records[match[0]].second);
            records[match[1]] = make_pair(records[match[1]].first, ++records[match[1]].second);
        }

        vector<vector<int>> result(2);

        for(auto& p: records){
            if(p.second.second == 0){
                result[0].emplace_back(p.first);
            }else if(p.second.second == 1){
                result[1].emplace_back(p.first);
            }
        }

        sort(result[0].begin(), result[0].end());
        sort(result[1].begin(), result[1].end());

        return result;
    }
};