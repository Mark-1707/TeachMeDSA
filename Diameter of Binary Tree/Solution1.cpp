// https://leetcode.com/problems/diameter-of-binary-tree/description/

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
     int ans = 0;
    int findHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        return 1 + max(findHeight(root->left), findHeight(root->right));

    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        findMax(root);

        return ans;
    }

    void findMax(TreeNode* root){
        
         if(root == NULL){
            return;
        }

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        ans = max(ans, lh+rh);

        findMax(root->left);
        findMax(root->right);
    }

};