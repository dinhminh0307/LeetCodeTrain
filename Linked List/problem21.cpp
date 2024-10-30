#include <iostream>

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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //dummy points to the first node of the merged list.
        ListNode dummy(0);
        ListNode* node = &dummy;
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else if(list2->val <= list1->val) {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next; // move the node to the added node to continue to perform next node
        }
        
        // in case some list still have more nodes
        if(list1) {
            node->next = list1;
        } else{
            node->next = list2;
        }
        return dummy.next;
    }
};