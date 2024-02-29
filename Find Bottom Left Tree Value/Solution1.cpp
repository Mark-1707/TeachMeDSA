// https://leetcode.com/problems/find-bottom-left-tree-value/

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
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        if(!root->left && !root->right) return root->val;

        queue<TreeNode*> q;
        q.push(root);
        int ans;

        while(q.size()){
            int size = q.size();
            while(size--){
                TreeNode* top = q.front();
                q.pop();
                if(top->right){
                    q.push(top->right);
                }
                if(top->left){
                    ans = top->left->val;
                    q.push(top->left);
                }else if(top->right){
                    ans = top->right->val;
                }
            }
        }
        return ans;
    }
};