// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;

        unordered_set<char> set;
        int counter = 0;
        int max_len = 0;

        while(l <= r && r < s.size()){
            if(set.find(s[r]) != set.end()){
                max_len = max(counter, max_len);
                set = {};
                counter  = 0;
                l = l+1;   
                r = l;             
            }else{
                counter++;
                set.insert(s[r]);
                r = r+1;
            }
        }
        return max(max_len, counter);
    }
};