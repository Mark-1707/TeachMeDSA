// https://leetcode.com/problems/sort-characters-by-frequency/description/

#include<bits/stdc++>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;

        for(const char& ch: s) map[ch]++;

        vector<pair<char, int>> sortedPairs(map.begin(), map.end());

        sort(sortedPairs.begin(), sortedPairs.end(), [](const pair<char, int> a, const pair<char, int> b){
            return a.second > b.second;
        });

        string ans = "";

        for(pair<char, int>& ch: sortedPairs){
            int temp = ch.second;
            while(temp--) ans += ch.first;
        }

        return ans;
    }
};