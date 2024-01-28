// https://leetcode.com/problems/add-two-numbers/description/


#include <bits/stdc++.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        
        // ListNode* ans = dummy;
        int carry = 0;
        while(l1  || l2){
            ListNode* node = new ListNode();

            ListNode* dummy = new ListNode();
            if(l1 == NULL){
                l1 = dummy;
                l1->val = 0;
                l1->next = NULL;
            }else if(l2 == NULL){
                l2 = dummy;
                l2->val = 0;
                l2->next = NULL;
            }
            
            int val = (l1->val + l2->val) % 10;

            node->val = (val + carry) % 10;
            node->next = NULL;

            ans->next = node;

            carry = (((l1->val + l2->val) + (val+carry) / 10) / 10);

            
                l1 = l1->next;
            
                l2 = l2->next;
            
            ans = ans->next;
        }
        if(carry){
            ListNode* node = new ListNode();
            node->val = carry;
            node->next = NULL;
            ans->next = node;
        }
        return temp->next;  
    }
};