// https://leetcode.com/problems/remove-nodes-from-linked-list/description

#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;

        ListNode* ans = new ListNode();
        ans->next = NULL;

        while(head){
            if(st.empty()){
                st.push(head);
            }else{
                while(!st.empty() && st.top()->val < head->val){
                    st.pop();
                }
                st.push(head);
            }
            ListNode* temp = head;
            head = head->next;
            temp->next = nullptr;
        }

        head = st.top();

        while(!st.empty()){
            cout<<st.top()->val<<" ";
            ans->next = st.top();
            st.pop();
            ans = ans->next;
        }

        ListNode* next = head;
        ListNode* prev = NULL;

        while(head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = next;
            next = temp;
            head = temp;
        }

        return prev;
        
    }
};