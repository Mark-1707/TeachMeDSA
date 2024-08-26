// https://leetcode.com/problems/n-ary-tree-postorder-traversal/description


#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node(int _val) {
        val = _val;
    }
};

class Solution {
    vector<int> res;
    void helper(Node* root) {
        if(!root) return;
        for(auto& it: root->children) {
            helper(it);
        }
        res.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        helper(root);
        return res;
    }
};