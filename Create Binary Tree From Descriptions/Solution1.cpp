// https://leetcode.com/problems/create-binary-tree-from-descriptions/description

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> map;
        unordered_set<int> set;

        for(const auto& v : descriptions){
            set.insert(v[1]);
            if(map.find(v[0]) == map.end()){
                map[v[0]] = new TreeNode(v[0]);
            }

            if(map.find(v[1]) == map.end()){
                map[v[1]] = new TreeNode(v[1]);
            }

            if(v[2] == 1){
                map[v[0]]->left = map[v[1]];
            }else{
                map[v[0]]->right = map[v[1]];
            }

        }

        for(const auto& v : descriptions){
            if(set.find(v[0]) == set.end()) return map[v[0]];
        }

        return map[0];
    }
};
