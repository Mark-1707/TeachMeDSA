// https://leetcode.com/problems/reverse-string/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for(int i=len-1; i > len/2-1; i--){
            int t = len % (i+1);
            char temp = s[t];
            s[t] = s[i];
            s[i] = temp;
        }
    }
};