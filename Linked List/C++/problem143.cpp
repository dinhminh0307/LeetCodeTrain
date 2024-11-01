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
//         This line disconnects the first half of the list from the second half.
// By setting slow->next to nullptr, we effectively split the list into two independent parts:
// The first half, starting from head and ending at slow
// The second half, starting from tmp
        slow->next = nullptr; // cut the list into 2 halves
        ListNode* prev = nullptr; //This pointer will help us build the reversed list.

        // when the loop end, the middle node is slow
        // reverse the second half linkedlist
        while(tmp) {
            ListNode* nextNode = tmp->next;
            tmp->next = prev; //e reverse the pointer of the current node (tmp) to point back to the previous node (prev), reversing the direction.
            prev = tmp; //We move prev forward to the current node (tmp). 
            tmp = nextNode; // We move tmp forward to the next node (nextNode) to continue the loop.
        }
        ListNode* second = prev; // The head of the reversed second half
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