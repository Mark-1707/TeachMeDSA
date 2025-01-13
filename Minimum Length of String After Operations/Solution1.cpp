// https://leetcode.com/problems/minimum-length-of-string-after-operations/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> map;
        int count = 0;
        for(const char& ch: s) {
            map[ch]++;
            count++;
            if(map[ch] > 2) {
                map[ch] -= 2;
                count -= 2;
            }
        }
        return count;
    }
};
