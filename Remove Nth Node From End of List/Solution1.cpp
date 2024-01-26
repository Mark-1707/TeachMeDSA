// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* node = head;
        while(node != NULL){
            node = node->next;
            count++;
        }

        node = head;

        int index = 1;
        ListNode* prev = head;

        if(n == count) return head->next;

        while(count - index + 1 != n){
            prev = node;
            node = node->next;
            index++;            
        }

        prev->next = node->next;
        return head;
    }
};