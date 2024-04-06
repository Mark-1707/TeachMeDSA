// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int open = 0;
        int close = 0;
        for(const char& ch: s){
            if(ch == '(') open++;
            else if(ch == ')') close++;
            if(close > open){
                close--;
                continue;
            }
            ans += ch;
        }

        open = 0;
        close = 0;
        string finalAns = "";
        for(int i=ans.size() - 1; i>=0; i--){
            if(ans[i] == ')') close++;
            else if(ans[i] == '(') open++;
            if(open > close){
                open--;
                continue;
            }
            finalAns += ans[i];
        }
        reverse(finalAns.begin(), finalAns.end());
        return finalAns;
    }
};