// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description

#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
    void addOne(string& s){
        int i = s.size() - 1;
        while(i >= 0 && s[i] == '1'){
            s[i--] = '0';
        }
        if(i == -1){
            s.insert(0, 1, '1');
        }else{
            s[i] = '1';
        }
    }

public:
    int numSteps(string s) {
        
        int count = 0;

        while(s != "1"){
            if(s.back() == '0'){
                s.pop_back();
            }else{
                addOne(s);
            }

            count++;
        }


        return count;
    }
};  