// https://leetcode.com/problems/top-k-frequent-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Store the frequency of each element in a map
        unordered_map<int, int> counter;

        for(auto it = nums.begin(); it != nums.end(); it++){
            counter[*it]++;
        }

        vector<pair<int, int>> count;
        
        vector<int> ans;

        // Store the map in a vector of pairs
        for(auto it = counter.begin(); it != counter.end(); it++){
            count.emplace_back(*it);
        }

        // Sort the vector of pairs in descending order of frequency
        sort(count.begin(), count.end(), [](pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        });

        // Push the first k elements in the ans vector
        for(int i=0; i<k; i++){
            ans.emplace_back(count[i].first);
        }

        return ans;
    }
};