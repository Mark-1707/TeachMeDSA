// https://leetcode.com/problems/counting-words-with-a-given-prefix/description

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(const string& word: words) {
            if(word.substr(0, pref.size()) == pref) count++;
        }
        return count;
    }
};