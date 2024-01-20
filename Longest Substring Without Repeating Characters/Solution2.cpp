// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;

        unordered_set<char> set;
        queue<char> q;

        int res = 0;

        for(int i=0; i< s.size(); i++){
            if(set.find(s[i]) != set.end()){
                res = max(res, int(q.size()));
                while(q.front() != s[i]) {
                    set.erase(q.front());
                    q.pop();
                }
                q.pop();
                q.push(s[i]);
            }else{
                q.push(s[i]);
                set.insert(s[i]);
            }
        }

        return max(res, int(q.size()));
    }
};