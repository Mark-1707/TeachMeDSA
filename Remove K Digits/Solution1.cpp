// https://leetcode.com/problems/remove-k-digits/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(const char& ch: num){
            while(!st.empty() && st.top() > ch && k){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(k){
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int i=0;
        while(ans[i] == '0' && i < ans.size()) i++;

        ans.erase(0, i);

        if(ans == "") return "0";
        
        return ans;
    }
};