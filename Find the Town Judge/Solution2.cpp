// https://leetcode.com/problems/find-the-town-judge/description/

#include<bits/stdc++.j>
using namespace std;

// time complexity: O(V)

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if(n == 1) return 1;

        unordered_map<int, int> incoming;
        unordered_map<int, int> outgoing;
        unordered_set<int> set;

        for(vector<int>& v: trust){
            outgoing[v[0]]++;
            incoming[v[1]]++;
            set.insert(v[0]);
            set.insert(v[1]);
        }

        int size = set.size();

        for(const int& s: set){
            if(incoming[s] == size - 1 && outgoing[s] == 0) return s;
        }
        
        return -1;
    }
};