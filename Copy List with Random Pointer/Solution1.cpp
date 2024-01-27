// https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;

        Node* temp = head;

        while(temp){
            map[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;

        while(temp){
            Node* newNode = map[temp];
            newNode->random = map[temp->random];
            newNode->next = map[temp->next];
            temp = temp->next;
        }

        return map[head];
    }
};