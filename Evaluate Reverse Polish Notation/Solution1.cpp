// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int calculate(int num1, int num2, string op){
        if(op == "+") return num1 + num2;
        if(op == "-") return num1 - num2;
        if(op == "/") return num1 / num2;
        if(op == "*") return num1 * num2;

        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> solver;
        unordered_set<string> op{"+", "-", "*", "/"};

        for(int i=0; i<tokens.size(); i++){
            if(op.count(tokens[i])){
                int num2 = solver.top();
                solver.pop();
                int num1 = solver.top();
                solver.pop();
                solver.push(calculate(num1, num2, tokens[i]));
            }else{
                solver.push(stoi(tokens[i]));
            }
        }
        return solver.top();
    }
};