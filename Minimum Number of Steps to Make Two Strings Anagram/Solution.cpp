// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> s1, t1;

        for(int i = 0; i<s.size(); i++){
            s1[s[i]]++;
            s1[t[i]]--;
        }

        int ans = 0;
        for(auto& it: s1){
            ans += max(0, s1[it.first]);
        }

        return ans;
    }
};