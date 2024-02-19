// https://leetcode.com/problems/subtree-of-another-tree/description/

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

    bool check(TreeNode* p, TreeNode* q){
        if(p->val == q->val) return true;
        return false;
    }

    bool sameTree(TreeNode* p, TreeNode* q){

        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;

        bool isSame = check(p, q);
        if(!isSame) return false;

        return sameTree(p->left, q->left) && sameTree(p->right, q->right);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root == NULL && subRoot == NULL) return true;
        if(root == NULL && subRoot != NULL) return false;
        if(root != NULL && subRoot == NULL) return false;

        bool isSame =  sameTree(root, subRoot);
        if(isSame) return true;


        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};