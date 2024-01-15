// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, pair<int, int>> records;
        unordered_set<int> players;

        for(auto& match: matches){

            int count = records.count(match[0]) ? 0 : 1;
            records[match[0]] = make_pair(records[match[0]].first + count, records[match[0]].second);
            if(!count){
                records[match[0]] = make_pair(++records[match[0]].first, records[match[0]].second);
            }

            players.insert(match[0]);

            count = records.count(match[1]) ? 0 : 1;
            records[match[1]] = make_pair(records[match[1]].first, records[match[1]].second + count);
            if(!count){
                records[match[1]] = make_pair(records[match[1]].first, records[match[1]].second + 1);
            }
            
            players.insert(match[1]);
            
        }

        vector<vector<int>> result(2);

        for(const int& p: players){
            
            if(records[p].second == 0){
                result[0].emplace_back(p);
            }else if(records[p].second == 1){
                result[1].emplace_back(p);
            }
        }

        sort(result[0].begin(), result[0].end());
        sort(result[1].begin(), result[1].end());

        return result;
    }
};