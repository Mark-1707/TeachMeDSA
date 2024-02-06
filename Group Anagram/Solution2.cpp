// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<string> v;

        for(int i=0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            v.emplace_back(temp);
        }

        int count = 0;
        for(int i=0; i<v.size(); i++){
            if(map.find(v[i]) != map.end()) continue;
            map[v[i]] = count++;
        }

        vector<vector<string>> ans(map.size());

        for(int i=0; i<v.size(); i++){
            ans[map[v[i]]].push_back(strs[i]);
        }

        return ans;
    }
};