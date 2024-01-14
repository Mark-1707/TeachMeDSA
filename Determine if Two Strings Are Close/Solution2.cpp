// https://leetcode.com/problems/determine-if-two-strings-are-close/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if(word1.size() != word2.size()) return false;

        array<int, 26> count1 = {};
        array<int, 26> count2 = {};

        for(char& c: word1){
            ++count1[c - 'a'];
        }

        for(char& c: word2){
            ++count2[c - 'a'];
        }

        for(int i=0; i<26; i++){

            bool c1 = count1[i] > 0;
            bool c2 = count2[i] > 0;

            if((c1 && !c2) || (!c1 && c2)) return false;
        }

        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        for(int i=0; i<26; i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }
};
