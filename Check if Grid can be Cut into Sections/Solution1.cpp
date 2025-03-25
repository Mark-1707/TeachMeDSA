// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int countNonOverlapping(vector<pair<int, int>> intervals) {
        int count = 0;
        int priv_end = -1;

        for(int i = 0; i < intervals.size(); i++){
            if(priv_end <= intervals[i].first) count++;
            priv_end = max(priv_end, intervals[i].second);
        }

        return count;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> x;
        vector<pair<int, int>> y;

        for(int i = 0; i < rectangles.size(); i++){
            x.push_back(make_pair(rectangles[i][0], rectangles[i][2]));
        }

        for(int i = 0; i < rectangles.size(); i++){
            y.push_back(make_pair(rectangles[i][1], rectangles[i][3]));
        }

        sort(x.begin(), x.end(), [](auto& p1, auto& p2){
            return p1.first < p2.first;
        });

        sort(y.begin(), y.end(), [](auto& p1, auto& p2){
            return p1.first < p2.first;
        });

        return max(countNonOverlapping(x), countNonOverlapping(y)) >= 3;
    }
};