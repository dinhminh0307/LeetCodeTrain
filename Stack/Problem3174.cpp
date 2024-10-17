/**
 * https://leetcode.com/problems/clear-digits/description/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

/**
 * Solution: initialize a stack to keep track the indice, push every char to the stack, if meet digit, pop 2 times
 * then push to the string and reverse the string
 */

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string res = "";
        for(char& c : s) {
            st.push(c);
            if(isdigit(c)) {
                st.pop();
                st.pop();
            }
        }

        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};