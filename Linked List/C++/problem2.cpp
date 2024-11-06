#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* res = result;
        int n = 0; // to keep track the modular
        int sum = 0; // to keep tract the next node
        while(true) {
            // to handle case one of the list node is empty
            if(l1 == nullptr && l2) {
                sum = l2->val + n;
            } else if(l2 ==  nullptr && l1) {
                sum = l1->val + n;
            } else if(l1 && l2) {
                sum = l1->val + l2->val + n;
                
            }
            
            // if l1.val + l2.val >= 10, we keep for the modular for the next operation
            if(sum >= 10) {
                n = sum / 10;
                
                res->next = new ListNode(sum % 10);
            } else {
                n = 0;
                res->next = new ListNode(sum);
            }
            
            // traverse to the next node
            if(l1) {
                l1 = l1->next;
            }
            
            if(l2) {
                l2 = l2->next;
            }
            
            res = res->next;

            if(l1 == nullptr && l2 == nullptr) {
                break;
            }
        }

        // if both the list end, and still got the modular, append to the list
        if(n > 0) {
            res->next = new ListNode(n);
        }
        return result->next;
    }
};

void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        head = head->next;
        if (head != nullptr) cout << " -> ";
    }
    cout << endl;
}



int main(void) {
    Solution sol;
    
    // Define the first number as a linked list: 2 -> 4 -> 3 (represents 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Define the second number as a linked list: 5 -> 6 -> 4 (represents 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Add the two numbers
    ListNode* result = sol.addTwoNumbers(l1, l2);
    
    // Print the result
    cout << "Result: ";
    printLinkedList(result); // Expected output: 7 -> 0 -> 8 (represents 807)

    return 0;
}