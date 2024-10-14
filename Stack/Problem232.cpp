/*https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=problem-list-v2&envId=stack*/

#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class MyQueue {
private:
    stack<int> st1;
    vector<int> store;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
        store.push_back(x);
    }
    
    int pop() {
        if(st1.empty() || store.empty()) {
            return 0;
        }
        int res = store[0];
        store.erase(store.begin());
        st1.pop();
        return res;
    }
    
    int peek() {
        if(store.empty()) {
            return 0;
        }
        return store[0];
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */