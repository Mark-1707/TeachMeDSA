// https://leetcode.com/problems/find-if-path-exists-in-graph/description

#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    bool canReach(int n, vector<vector<int>> &edges, int source, int destination, vector<bool> &vis)
    {
        vis[source] = true;
        for (int &it : edges[source])
        {
            if (!vis[it])
            {
                if (it == destination)
                    return true;
                if (canReach(n, edges, it, destination, vis))
                    return true;
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {

        if (source == destination)
            return true;

        vector<bool> vis(n, false);
        vector<vector<int>> graph(n);

        for (vector<int> &it : edges)
        {
            graph[it[0]].emplace_back(it[1]);
            graph[it[1]].emplace_back(it[0]);
        }

        return canReach(n, graph, source, destination, vis);
    }
};