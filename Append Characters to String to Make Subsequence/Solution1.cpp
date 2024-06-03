// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int index = 0;
        int r = 0;

        int ans = t.size();

        while(r < s.size()){
            if(s[r] == t[index]){
                while(r < s.size() && index < t.size() && s[r] == t[index]){
                    r++;
                    index++;
                    int len = t.size() - index;
                    ans = min(ans, len);
                }
            }else{
                r++;
            }
        }
        return ans;
    }
};