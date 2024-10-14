/**
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
#include <string>

using namespace std;

/**
 * In RPN, you evaluate the expression from left to right:

When you encounter a number, you push it onto a stack.
When you encounter an operator, you pop the required number of operands from the stack, perform the operation, and push the result back onto the stack.
Step-by-Step Breakdown:
"4": It's a number, so push it onto the stack.
Stack: [4]

"13": It's a number, so push it onto the stack.
Stack: [4, 13]

"5": It's a number, so push it onto the stack.
Stack: [4, 13, 5]

"/": This is an operator that requires two operands. Pop the top two numbers from the stack (13 and 5), divide them (13 / 5 = 2), and push the result back onto the stack.
Stack after division: [4, 2]

"+": This is an operator that also requires two operands. Pop the top two numbers from the stack (4 and 2), add them (4 + 2 = 6), and push the result back onto the stack.
Stack after addition: [6]

At the end, the only number left in the stack is 6, which is the result of the expression.
 */

class Solution {
public:
    bool check_int(string s) {
        for(int  i = 0; i < s.length(); i++) {
            if(s[0] == '-' && s.length() > 1) {
                continue;
            }

            if(isdigit(s[i])) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& s : tokens) {
            if(check_int(s)) {
                int num = stoi(s);
                st.push(num);
            } else if(s == "+" && st.size() > 1) {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first + second);
            } else if(s == "-" && st.size() > 1) {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second - first);
            } else if(s == "*" && st.size() > 1) {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first * second);
            } else if(s == "/" && st.size() > 1) {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if (first == 0) {
                    throw runtime_error("Division by zero error");
                }
                st.push(second / first);
            }
            // cout << st.top() << endl;
        }
        return st.top();
    }
};

int main(void) {
    Solution sol;
    vector<string> str = {"4","3","-"};
    sol.evalRPN(str);
}