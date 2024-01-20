// https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int l = 0;
        int r = 0;
        int res = 0;
        bool left = true;
        while(l<=r && r < s.size()){
            if(left) map[s[r]]++;
            auto max_freq = std::max_element(map.begin(), map.end(),
            [](const std::pair<char, int> &p1, const std::pair<char, int> &p2)
            {
                return p1.second < p2.second;
            });

            int max_frequency = (max_freq != map.end()) ? max_freq->second : 0;

            if(((r-l+1) - max_frequency) <= k){
                res = max(res, r-l+1);
                r++;
                left = true;
            }else{
                map[s[l]]--;
                l++;
                left = false;
            }
        }
        return res;
    }
};