// https://leetcode.com/problems/sum-root-to-leaf-numbers/description

#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {

private:

    int dfs(TreeNode* root, int num){
        if(!root) return 0;

        num = num * 10 + root->val;

        if(!root->left && !root->right) return num;

        return dfs(root->left, num) + dfs(root->right, num);

    }

public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};