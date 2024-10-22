// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/

#include<bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
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
vector<long long> sum;
void bfs(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int len = q.size();
        long long tempSum = 0;
        for(int i = 0; i < len; i++) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
            tempSum += temp->val;
        }
        sum.push_back(tempSum);
    }
}
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        bfs(root);
        sort(sum.begin(), sum.end());
        if(sum.size() < k) return -1;
        return sum[sum.size() - k];
    }
};