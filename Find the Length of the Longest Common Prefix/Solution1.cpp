// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> set1;
        int ans = 0;

        for(int& s: arr1) {
            string word = to_string(s);
            string sub = "";
            for(const char& ch: word) {
                sub += ch;
                set1.insert(sub);
            }
        }

        for(int& s: arr2) {
            string word = to_string(s);
            string sub = "";
            for(const char& ch: word) {
                sub += ch;
                if(set1.find(sub) != set1.end()) {
                    int len = sub.size();
                    ans = max(len, ans);
                }
            }
        }
        return ans;
    }
};