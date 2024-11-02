#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Solution: take the use of fast and slow pointer:
 * if fast meet slow, the linked list is in cycle
 * if not, fast will run till the nullptr
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast) {
                return true;
            }
        }
        return false;
    }
};