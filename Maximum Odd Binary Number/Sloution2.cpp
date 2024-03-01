// https://leetcode.com/problems/maximum-odd-binary-number/description/

// time complexity O(n)  Partitioning Algo
// space complexity O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int l = 0;
        int r = 0;
        while(r < s.size()){
            if(s[r] == '1'){
                s[r] = '0';
                s[l] = '1';
                l++;
            }
            r++;
        }
        s[l-1] = '0';
        s[int(s.size()) - 1] = '1';
        return s;
    }
};