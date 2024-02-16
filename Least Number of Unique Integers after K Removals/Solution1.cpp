// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        for(int& n: arr) map[n]++;
        
        vector<pair<int, int>> v(map.begin(), map.end());

        sort(v.begin(), v.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b){
            return a.second < b.second;
        });

        for(const pair p: v){
            if(k == 0) break;
            if(p.second <= k){
                map.erase(p.first);
                k -= p.second;
            }
        }
        return map.size();
    }
};