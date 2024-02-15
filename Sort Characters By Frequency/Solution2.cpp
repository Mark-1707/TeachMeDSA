// https://leetcode.com/problems/sort-characters-by-frequency/description/

#include<bits/stdc++>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        unordered_map<int, vector<char>> v;

        for(const char& ch: s) map[ch]++;

        for (auto& entry : map) {
            char ch = entry.first;
            int freq = entry.second;
            v[freq].push_back(ch);
        }

        string ans = "";

       for (int i = s.size(); i > 0; i--) {
            if (v.find(i) != v.end()) {
                for (const char& ch : v[i]) {
                    for (int j = 0; j < i; j++) {
                        ans += ch;
                    }
                }
            }
        }

        return ans;
    }
};