// https://leetcode.com/problems/merge-intervals/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
        });

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        int n = intervals.size();
        for(int i=1; i<n; i++){
            if(intervals[i-1][1] >= intervals[i][0]){
                intervals[i-1][0] = min(intervals[i-1][0], intervals[i][0]);
                intervals[i-1][1] = max(intervals[i-1][1], intervals[i][1]);

                intervals[i][0] = intervals[i-1][0];
                intervals[i][1] = intervals[i-1][1];

                if(i == 1) ans.pop_back();
                
            }
            if(!ans.empty() && ans.back()[1] >= intervals[i][0]){
                ans.pop_back();
            }

            ans.push_back(intervals[i]);
        }

        return ans;
    }
};

// 0 2, 1 4, 3 5

// 0 4, 