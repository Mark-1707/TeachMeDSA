// https://leetcode.com/problems/binary-tree-postorder-traversal/description/
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Recursive Solution
 * 
 */


struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution {
    vector<int> ans;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        ans.push_back(root->val);
        return;
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};