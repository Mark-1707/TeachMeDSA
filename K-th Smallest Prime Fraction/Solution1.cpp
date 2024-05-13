// https://leetcode.com/problems/k-th-smallest-prime-fraction/description

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        auto cmp = [](const pair<pair<int, int>, float>& p1, const pair<pair<int, int>, float>& p2) {
            return p1.second < p2.second;
        };

        priority_queue<pair<pair<int, int>, float>, vector<pair<pair<int, int>, float>>, decltype(cmp)> q(cmp);
        
        int n = arr.size();
        for(int i=0; i < n; i++){
            for(int j=i+1; j<n; j++){
                q.push({{arr[i], arr[j]}, ((float)arr[i] / arr[j])});
            }
        }

        while(q.size() > k){
            q.pop();
        }

        return {q.top().first.first, q.top().first.second};

    }
};