// https://leetcode.com/problems/number-of-lines-to-write-string/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int width = 0;
        int height = 1;
        unordered_map<char, int> map;
        for(int i=0; i<26; i++) map[char(97+i)] = widths[i];

        for(const char& ch: s){
            width += map[ch];
            if(width > 100){
                height++;
                width = map[ch];
            }
        }
        return {height, width};
    }
};