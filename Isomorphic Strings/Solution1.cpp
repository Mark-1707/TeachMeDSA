// https://leetcode.com/problems/isomorphic-strings/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, char> map;
        unordered_set<char> set;
        for(int i=0; i<s.size(); i++){
            if(map.find(s[i]) != map.end()){
                if(map[s[i]] != t[i]) return false;
            }else if(map.find(t[i]) != map.end()){
                if(map[t[i]] == t[i]) return false;
            }else if(set.find(t[i]) != set.end()) return false;
            map[s[i]] = t[i];
            set.insert(t[i]);
        }
        return true;
    }
};