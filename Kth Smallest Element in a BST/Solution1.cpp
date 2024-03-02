// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    int count = 0;
    int ans;
    void find(TreeNode* root, int k){
        if(!root) return;
        find(root->left, k);
        count++;
        if(k == count){
            ans = root->val;
            return;
        }
        find(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        find(root, k);
        return ans;
    }
};