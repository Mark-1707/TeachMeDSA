// https://leetcode.com/problems/determine-if-two-strings-are-close/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if(word1.size() != word2.size()) return false;

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        vector<int> count1;
        vector<int> count2;

        unordered_set<char> s1;
        unordered_set<char> s2;

        for(int i=0; i<word1.size(); i++){
            map1[word1[i]]++;
            map2[word2[i]]++;
            s1.insert(word1[i]);
            s2.insert(word2[i]);
        }

        for(const char& c: s1){
            count1.emplace_back(map1[c]);
        }

        for(const char& c: s2){
            if(!map1.count(c)) return false;
            count2.emplace_back(map2[c]);
        }

        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        for(int i=0; i<s1.size(); i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }
};