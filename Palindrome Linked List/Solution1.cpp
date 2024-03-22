// https://leetcode.com/problems/palindrome-linked-list/description/

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
    bool isPalindrome(ListNode* head) {
        string s1 = "";
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;
            s1 += to_string(curr->val);
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        string s2 = "";
        while(prev){
            s2 += to_string(prev->val);
            prev = prev->next;
        }

        return s1==s2;
    }
};
