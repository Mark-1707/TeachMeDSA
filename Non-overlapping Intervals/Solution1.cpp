// https://leetcode.com/problems/non-overlapping-intervals/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& v1, const auto& v2){
            return v1[0] < v2[0];
        });

        int i=0;
        int n = intervals.size();
        int count = 0;

        while(i < n-1){
            if(intervals[i][1] > intervals[i+1][0]){
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = min(intervals[i][1], intervals[i+1][1]);
                count++;
            }
            i++;
        }
        return count;
    }
};