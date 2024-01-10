// https://leetcode.com/problems/valid-palindrome/solutions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if((s[i] >= 65 && s[i] <=90) || (s[i]>=97 && s[i] <=122) || (s[i]>=48 && s[i] <=57)){
                ans += (char)tolower(s[i]);
            }
        }

        int len = ans.size();
        int mid = len/2;
        int l = 0;
        int r = len-1;
        if(len%2 == 0){
            mid -=1;
        }

        while( l<= mid && r>=mid){
            if(ans[l] != ans[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};