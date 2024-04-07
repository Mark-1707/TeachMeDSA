// https://leetcode.com/problems/valid-parenthesis-string/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
    bool checkValidString(string s) {
        int leftMin = 0;
        int leftMax = 0;
        for(const char& ch: s){
            if(ch == '('){
                leftMin++;
                leftMax++;
            }else if(ch == ')'){
                leftMin--;
                leftMax--;
            }else if(ch == '*'){
                leftMin--;
                leftMax++;
            }
            if(leftMax < 0) return false;
            if(leftMin < 0) leftMin = 0;
        }
        return leftMin == 0;
    }
};