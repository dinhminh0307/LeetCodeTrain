/**
 * https://leetcode.com/problems/backspace-string-compare/description/?envType=problem-list-v2&envId=stack
 */

#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;

        // for frist string
        for(auto& c : s) {
            if(c != '#') {
                st1.push(c);
            } else {
                if(st1.empty()) {
                    continue;
                }
                st1.pop();
            }
        }

        for(auto& c : t) {
            if(c != '#') {
                st2.push(c);
            } else {
                if(st2.empty()) {
                    continue;
                }
                st2.pop();
            }
        }

        if(st2.empty() && st1.empty()) {
            return true;
        } else if(st1.size() != st2.size()) {
            return false;
        }

        while(!st1.empty() || !st2.empty()) {
            if(st1.top() == st2.top()) {
                st1.pop();
                st2.pop();
            } else {
                return false;
            }
        }
        return true;
    }
};