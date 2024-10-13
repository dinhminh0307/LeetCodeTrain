/**
 * https://leetcode.com/problems/min-stack/description/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

/**
 * Solution: create that stack to stick another stack inside it, adn implement the method base on the given method of stack
 * Push the element of the to both stack, if the element is smallest, push to top of minium, other wise not. and when get min
 * just return the top of the minium stack
 */

class MinStack {
private:
    stack<int> min_stack;
    stack<int> minium;
public:
    MinStack() {
        
    }
    
    void push(int val) { // 0 -1 -3
                        // 0 -1 2 -3
        min_stack.push(val);
        if(minium.empty() || val <= minium.top()) { // handle minium empty first before accessing to top
            minium.push(val);
            // s.insert(val);
        }
        
    }
    
    void pop() {
        // int current = min_stack.top();
        // auto it = s.find(current);
        // if(it != s.end() ) {
            
        // }
        if(min_stack.empty() || minium.empty()) {
            return;
        }

        if(min_stack.top() == minium.top()) {
            minium.pop();
        }
        min_stack.pop();
    }
    
    int top() {
        if(min_stack.empty()) {
            return 0;
        }
        return min_stack.top();
    }
    
    int getMin() {
        if(minium.empty()) {
            return 0;
        }
        return minium.top();
    }
};