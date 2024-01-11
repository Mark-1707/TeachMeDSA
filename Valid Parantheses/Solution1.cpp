// https://leetcode.com/problems/valid-parentheses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isValid(string s) {
        vector<char> stack;

        for(int i=0; i<s.size(); i++){

            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stack.push_back(s[i]);
            }else{
                if(stack.size()== 0 || 
                    (s[i] == ')' && stack.back() != '(') ||
                    (s[i] == ']' && stack.back() != '[') ||
                    (s[i] == '}' && stack.back() != '{')
                ){
                    return false;
                }
                stack.pop_back();
            }
        }
        return !stack.size();
    }
};