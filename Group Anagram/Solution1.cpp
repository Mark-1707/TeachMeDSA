// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        //2D Vector to return a group of anagrams
        vector<vector<string>> ans;

        //unordered_set to store the sorted strings and check if the group already exists
        unordered_set<string> ans_set;

        //unordered_map to store the position of the group in the ans vector
        unordered_map<string, int> positions;

        // pair to check if the string is already present in the set
        pair<unordered_set<string>::iterator, bool> set_flag;

        for(auto it = strs.begin(); it != strs.end(); it++){
            string temp = *it;
            sort(temp.begin(), temp.end());
            set_flag = ans_set.insert(temp);
            if(set_flag.second){
                positions[temp] = ans.size();
                ans.emplace_back(vector<string>{*it});
            }else{
                ans[positions[temp]].emplace_back(*it);
            }
        }
        return ans;
    }
};