// https://leetcode.com/problems/set-mismatch/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();

        for(int i=1; i<=n; i++){
            map[i]++;
        }

        for(int& i: nums){
            map[i]--;
        }

        int num1, num2;
        for(auto& p: map){
            if(p.second == -1) num1 = p.first;
            else if(p.second == 1) num2 = p.first;
        }

        return vector<int> {num1, num2};
    }
};