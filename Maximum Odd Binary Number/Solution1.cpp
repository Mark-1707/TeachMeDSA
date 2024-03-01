// https://leetcode.com/problems/maximum-odd-binary-number/description/

// time complexity O(n)
// space complexity O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        unordered_map<char, int> map;
        for(const char& ch: s) map[ch]++;

        string ans = "";
        for(int i = 0; i < map['1'] - 1; i++){
            ans += '1';
        }

        for(int i = 0; i < map['0']; i++){
            ans += '0';
        }
        return ans + '1';
    }
};