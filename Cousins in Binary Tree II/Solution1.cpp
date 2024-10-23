// https://leetcode.com/problems/cousins-in-binary-tree-ii/description/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> levelSum;
    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int len = q.size();
            int sum = 0;
            for(int i = 0; i < len; i++) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            levelSum.push_back(sum);
            level++;
        }
    }

    void bfsSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()) {
            int len = q.size();
            int sum = levelSum[level];
            for(int i = 0; i < len; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                int leftSelf = 0;
                if(temp->left) {
                    leftSelf = temp->left->val;
                    if(temp->right) {
                        temp->left->val = levelSum[level] - temp->right->val;
                    } else {
                        temp->left->val = levelSum[level] - temp->left->val;
                        leftSelf -= temp->left->val;
                    }

                    if(temp->left && temp->right) {
                        temp->left->val = temp->left->val - leftSelf;
                    }
                    q.push(temp->left);
                }
                if(temp->right) {
                    int self = temp->right->val;
                    if(temp->left) {
                        temp->right->val = levelSum[level] -leftSelf;
                    } else {
                        temp->right->val = levelSum[level] - self;
                    }
                    if(temp->left && temp->right) {
                        temp->right->val = temp->right->val - self;
                    }
                    q.push(temp->right);
                }
            }
            level++;
        }
    }

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        bfs(root);
        bfsSum(root);
        root->val = 0;
        return root;
    }
};