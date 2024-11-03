#include <iostream>

using namespace std;

/**
 * Solution: first get the length of the link lest and then find the position of the nth element
 * Then iterate from head to that pos - 1
 * delete by storing the next next val if( not null) to the next
 * then update the next
 * return the head
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode* tmp = head;
        ListNode* st = new ListNode(0);
        st->next = head;
        ListNode* res = st;
        
        int len = 0;
        
        while(tmp) {
            len++;
            tmp = tmp->next;
        }
       
        // cout << len << endl;
        int temp = len - n;
        
        if(temp < 0) return nullptr;
        
        for(int i = 0 ; i < temp; i++) {
            res = res->next;
        }
        cout << res->val << endl;
        ListNode* dummy = nullptr;
        if(res->next->next) {
            dummy = res->next->next;
        }
        
        // cout << dummy->val << endl;
        res->next = dummy;
        return st->next;
    }
};

int main(void) {
    Solution sol;
    ListNode* head = new ListNode(5);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(6);
    // head->next->next->next = new ListNode(8);
    // head->next->next->next->next = new ListNode(10);
    // head->next->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next->next = new ListNode(6);
    sol.removeNthFromEnd(head, 1);
}