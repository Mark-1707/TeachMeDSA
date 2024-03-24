// https://leetcode.com/problems/multiply-strings/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0") return "0";

        int len1 = num1.size();
        int len2 = num2.size();
        int len = len1 + len2;
        vector<int> v(len*2, 0);
        int index = (len*2) - 1;
        int count = 0;
        for(int i=len2-1; i>=0; i--){
            index = (len*2) - 1 - count;
            for(int j=len1-1; j>=0; j--){
                int temp = (int(num2[i] - 48) * int(num1[j] - 48))  + v[index];
                v[index] =  temp % 10;
                v[index-1] += temp/10;
                index--;
            }
            count++;
        }
        string ans = "";
        bool flag = false;
        int i = 0;
        for(;i<v.size(); i++){
            if(v[i]) break;
        }

        for(; i<v.size(); i++){
            ans += char(v[i] + 48);
        }

        return ans;
    }
};