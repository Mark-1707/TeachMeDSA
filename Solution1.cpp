// https://leetcode.com/problems/lexicographical-numbers/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> ans;
    void dfs(int cur, int n) {
        if(cur > n) {
            return;
        }
        ans.push_back(cur);
        cur *= 10;
        for(int i=0; i<10; i++) dfs(cur + i, n);
    }
public:
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i<10; i++) {
            dfs(i, n);
        }
        return ans;
    }
};