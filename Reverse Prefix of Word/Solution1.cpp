// https://leetcode.com/problems/reverse-prefix-of-word/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int l = 0;
        int r = 0;
        int len = word.size();
        while(r < len){
            if(word[r] == ch){
                while(l < r){
                    char temp = word[r];
                    word[r] = word[l];
                    word[l] = temp;
                    r--;
                    l++;
                }
                break;
            }
            r++;
        }
        return word;
    }
};