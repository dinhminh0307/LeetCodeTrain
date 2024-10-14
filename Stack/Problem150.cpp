/**
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
#include <string>

using namespace std;

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