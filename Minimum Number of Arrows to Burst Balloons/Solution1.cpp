// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description

// Time complexity: O(nlogn)
// Space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        int ans = 1;
        int min_end = INT_MAX;
        for(int i=0; i<points.size()-1; i++){
            int curr_start = points[i][0];
            int curr_end = points[i][1];
            int next_start = points[i+1][0];
            int next_end = points[i+1][1];
            min_end = min(curr_end, min_end);
            if(next_start <= min_end && curr_start <= next_start) continue;
            min_end = INT_MAX;
            ans++;
        }

        return ans;
    }
};

//             | | |  |  |  |
// | | | | | |
//   | | | | | | |
//                    |  |  |  |  |  |  |
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16