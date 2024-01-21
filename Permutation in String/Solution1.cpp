// https://leetcode.com/problems/permutation-in-string/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map1;

        for(const char& ch: s1 ){
            map1[ch]++;
        }

        if(s1.size() > s2.size()) return false;

        int window = s1.size();

        int l = 0;
        bool ans = false;
        while(l <= s2.size() - window ){
            unordered_map<char, int> map2;
            string s = s2.substr(l, window);
            for(const char& ch: s ){
                map2[ch]++;
            }
            
            for(const char& ch: s){
                if(map1[ch] != map2[ch]){
                    ans = false;
                    break;
                }else{
                    ans = true;
                }
            }

            if(ans) return true;
            l++;
        }

        return false;
    }
};