// https://leetcode.com/problems/daily-temperatures/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> arr(n, 0);
        
        stack<pair<int, int>> ele;
        
        for(int i=0; i<n; i++){
            while(!ele.empty() && ele.top().first < temperatures[i]){
                    arr[ele.top().second] = i - ele.top().second;
                    ele.pop();
            }
            ele.push({temperatures[i], i});
        }

        return arr;
    }
};