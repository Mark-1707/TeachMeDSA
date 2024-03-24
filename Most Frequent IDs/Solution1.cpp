// https://leetcode.com/problems/most-frequent-ids/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:
    struct CustomComparator {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.second < b.second;
        }
    };

public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> map;
        vector<long long> ans;
        priority_queue<pair<int, long long>, vector<pair<int, long long>> , CustomComparator> q;
        
        for(int i=0; i<nums.size(); i++){
            map[nums[i]] += freq[i];
            q.push(make_pair(nums[i], map[nums[i]]));
            while(!map.empty() && map[q.top().first] < q.top().second){
                q.pop();
            }
            ans.emplace_back(map[q.top().first]);
        }

        return ans;
    }
};