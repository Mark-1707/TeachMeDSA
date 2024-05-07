// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description

#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        vector<int> carry;

        ListNode* node = head;

        while(node){
            int num =  node->val * 2;
            int digit = num % 10;
            int carryDigit = num / 10;
            node->val = digit;
            carry.push_back(carryDigit);
            node = node->next;
        }

        carry.push_back(0);

        node = head;

        int i = 1;
        while(node){
            node->val += carry[i++];
            node = node->next;
        }

        ListNode* newHead = new ListNode();
        if(carry[0] != 0){
            newHead->val = carry[0];
            newHead->next = head;
        }else{
            newHead = head;
        }
        return newHead;
    }
};