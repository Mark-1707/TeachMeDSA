// https://leetcode.com/problems/count-elements-with-maximum-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> map;
        
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;    
        }
        
        vector<pair<int, int>> a;
        for(auto& i: map){
            a.emplace_back(i);
        }
        
        sort(a.begin(), a.end(), [](auto& b, auto& c){
            return b.second > c.second;
        });
        
        int sum = 0;
        int max = 0;
        for(auto& i: a){
            cout<<i.second<<endl;
            if(max > i.second && max !=0){
                return sum;
            }
            sum = sum + i.second;
            max = i.second;
        }
        return sum;
    }
};