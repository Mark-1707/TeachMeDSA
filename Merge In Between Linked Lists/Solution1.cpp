// https://leetcode.com/problems/merge-in-between-linked-lists/description/

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

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int index = 0;
        ListNode* start  = list1;
        ListNode* newStart = NULL;
        ListNode* newEnd = NULL;
        while(list1){
            if(index == a - 1){
                newStart = list1;
            }else if(index == b){
                newEnd = list1->next;
                break;
            }
            list1 = list1->next;
            index++;
        }

        newStart->next = list2;

        while(list2->next){
            list2 = list2->next;
        }

        list2->next = newEnd;

        return start;
    }
};