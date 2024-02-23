// https://leetcode.com/problems/find-the-town-judge/description/

#include<bits/stdc++.j>
using namespace std;

// time complexity: O(n^2)

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1) return 1;
        unordered_map<int, unordered_set<int>> map;
        unordered_set<int> s;
        unordered_set<int> ns;

        for(vector<int>& v1: trust){
            map[v1[0]].insert(v1[1]);
            s.insert(v1[0]);
            s.insert(v1[1]);
        }

        int ans = -1;
        
        for(const int& temp: s){
            if(map.find(temp) != map.end()) continue;
            ns.insert(temp);
            if(ns.size() > 1) return -1;
            bool isJudge = true;
            for(auto& m: map){
                if(m.second.find(temp) == m.second.end()){
                    isJudge = false;
                    break;
                }
            }
            if(isJudge) ans = temp;
        }
        return ans;
    }
};