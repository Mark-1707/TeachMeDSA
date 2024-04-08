// https://leetcode.com/problems/word-search-ii/description/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* link[26];
    bool flag;

    bool containsKey(char ch){
        return link[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        link[ch - 'a'] = node;
    }

    void setEnd(){
        flag = true;
    }
};

class Solution {
private:    
    Node* root;
    void dfs(vector<vector<char>>& board, int row, int col, int m, int n, vector<string>& res, Node* node, string word){

        if(row < 0 || col >= n || row >= m || col < 0 || board[row][col] == '#') return;

        char c = board[row][col];

        node = node->link[c - 'a'];
        if (node == NULL) {
            return;
        }

        word += board[row][col];
        if (node->flag) {
            res.push_back(word);
            node->flag = false;
        }

        board[row][col] = '#';

        dfs(board, row - 1, col, m, n, res, node, word);
        dfs(board, row, col + 1, m, n, res, node, word);
        dfs(board, row + 1, col, m, n, res, node, word);
        dfs(board, row, col - 1, m, n, res, node, word);

        board[row][col] = c;

    }

public:
    Solution(){
        root = new Node();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int m = board.size();
        int n = board[0].size();
        string word = "";
        for(const string& s: words){
            Node* node = root;
            for(const char& ch: s){
                if(!node->containsKey(ch)){
                    node->put(ch, new Node());
                }
                node = node->link[ch - 'a'];
            }
            node->setEnd();
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, m, n, res, root, word);
            }
        }

        return res;
    }
};