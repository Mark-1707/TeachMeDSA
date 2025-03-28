// https://leetcode.com/problems/flip-equivalent-binary-trees/ 

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        if(!r1 || !r2) return !r1 && !r2; 
        if(r1->val != r2->val) return false;

        bool a = flipEquiv(r1->left, r2->left) && flipEquiv(r1->right, r2->right);
        return a || flipEquiv(r1->left, r2->right) && flipEquiv(r1->right, r2->left);
    }
};