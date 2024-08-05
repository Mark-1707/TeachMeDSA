// https://leetcode.com/problems/kth-distinct-string-in-an-array/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        int count = 1;

        for(const string& it: arr) map[it]++;

        for(const string& it: arr) {
            if(map[it] == 1) {
                if(count == k) return it;
                count++;
            }
        }
        return "";
    }
};