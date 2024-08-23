// https://leetcode.com/problems/fraction-addition-and-subtraction/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionAddition(string exp) {
        int len = exp.size();
        int i = 0;
        int num = 0;
        int den = 1;

        while(i < len) {
            int curNum = 0;
            int curDen = 0;
            bool isNeg = (exp[i] == '-');

            if(exp[i] == '+' || exp[i] == '-') i++;

            while(i < len && isdigit(exp[i])) {
                int val = exp[i] - '0';
                curNum = (curNum * 10) + val;
                i++;
            }

            if(isNeg) curNum *= -1;

            i++;

            while(i < len && isdigit(exp[i])) {
                int val = exp[i] - '0';
                curDen = (curDen * 10) + val;
                i++;
            }

            num = num * curDen + curNum * den;
            den = den * curDen;
        }

        int GCD = abs(__gcd(num, den));
        num /= GCD;
        den /= GCD;

        return to_string(num) + "/" + to_string(den);
    }
};
