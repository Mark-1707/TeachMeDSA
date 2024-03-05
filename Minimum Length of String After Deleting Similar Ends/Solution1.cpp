// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int len = s.size();
        int l = 0;
        int r = len - 1;
        while(l < r && s[l] == s[r]){
            int temp = s[l];
            while(s[l] == temp && l <= r) l++;

            temp = s[r];
            while(s[r] == temp && l <= r) r--;
        }
        return (r-l+1);
    }
};