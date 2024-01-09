// https://neetcode.io/problems/string-encode-and-decode

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // using unordered_map to store the element order and size in encoded format
    unordered_map<int, int> order;

    string encode(vector<string>& strs) {
        order = {};
        string s = "";
        for(int i=0; i<strs.size(); i++){
            order[i] = strs[i].size();
            s = s.append(strs[i]);
        }
        return s;      
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int sum = 0;
        int index = 0;

        // Iterate over the unordered_map
        for(auto& it: order){

            // Push the substring from sum to sum + size[value of key in map] of the string
            ans.emplace_back(s.substr(sum, order[index]));
            sum += order[index];
            index++;
        }
        return ans;
    }
};
