// https://leetcode.com/problems/even-odd-tree/description/

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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int index = 0;
        while(!q.empty()){
            vector<int> increasing;
            vector<int> decreasing;
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                if((index%2 == 0) && (index != 1)){
                    if(node->val % 2 != 0){
                        if(!increasing.empty()){
                            if(increasing[increasing.size()-1] < node->val){
                                increasing.push_back(node->val);
                            }else{
                                return false;
                            }
                        }else{
                            increasing.push_back(node->val);
                        }
                    }else{
                        return false;
                    }
                }else{
                    if(node->val % 2 == 0){
                        if(!decreasing.empty()){
                            if(decreasing[decreasing.size()-1] > node->val){
                                decreasing.push_back(node->val);
                            }else{
                                return false;
                            }
                        }else{
                            decreasing.push_back(node->val);
                        }
                    }else{
                        return false;
                    }
                }
            }
            index++;
        }
        return true;
    }
};