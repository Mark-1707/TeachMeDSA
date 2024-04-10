// https://leetcode.com/problems/k-closest-points-to-origin/description/

#include<bits/stdc++.h>
using namespace std;

struct ComparePairs {
    bool operator()(const pair<float, pair<int, int>>& p1, const pair<float, pair<int, int>>& p2) const {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, ComparePairs> q;

        for(const auto& p: points){
            float dist = sqrt(pow(p[0], 2) + pow(p[1], 2));
            q.push(make_pair(dist, make_pair(p[0], p[1])));
        }

        vector<vector<int>> ans;

        int index = 1;
        while(index <= k &&!q.empty()){
            ans.push_back({q.top().second.first, q.top().second.second});
            q.pop();
            index++;
        }

        return ans;
    }
};