/**
 * https://leetcode.com/problems/valid-parentheses/description/?source=submission-noac
 */

#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

/**
 * Solution: because for the valid one, the open para always on the left so put it to the top of the stack:
 * 
 * Case1: (){}[] => go from left to right -> stack: ( /{ / [ and each of them can be eliminated if we find the value of closing one
 * Case2: ([]) => go from left to right : stack: ([ and when meet closing , it will eleminate
 * When the stack is empty, it is valid
 */

class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, char> tab = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> o;
        if(s.length() % 2 != 0) return false;
        for(auto& c : s) {
            auto it = tab.find(c);

            if(it != tab.end()) {
                if(o.empty()) return false;
                if(it->second != o.top()) {
                    return false;
                }
                
                o.pop();

            } else {
                o.push(c);
            }
        }
        return o.empty();
    }
};

int main(void) {
    Solution sol;
    cout << sol.isValid("()");
}

