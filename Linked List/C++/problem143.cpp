#include <iostream>
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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* res = head;
        ListNode* fast = head->next;
        while(fast && slow && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // cout << slow->val << endl;
        // while(slow && !slow->next) {
        //     cout << slow->val << " ";
        // }
        // cout << endl;
        ListNode* tmp = slow->next;
        slow->next = nullptr; // cut the list into 2 halves
        ListNode* prev = nullptr;

        // when the loop end, the middle node is slow
        // reverse the second half linkedlist
        while(tmp) {
            ListNode* nextNode = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = nextNode;
        }
        ListNode* second = prev; // The head of the reversed second half
        // while(temp) {
        //     cout << temp->val << endl;
        //     temp = temp->next;
        // }
        // now the second half linkedlist is reversed, merged into the first half
        ListNode* first = head;
        while(second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
        
    }
};

int main(void) {
    Solution sol;
    ListNode* head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = new ListNode(10);
    // head->next->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next->next = new ListNode(6);
    sol.reorderList(head);
}