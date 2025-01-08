// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPrefixAndSuffix(string str1, string str2) {
        if(str2.size() >= str1.size()) {
            for(int i = 0; i < str1.size(); i++) {
                if(str1[i] != str2[i]) return false;
                if(str1[str1.size() - i - 1] != str2[str2.size() - i - 1]) return false;
            }
        } else {
            return false;
        }
        return true;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                if(isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};