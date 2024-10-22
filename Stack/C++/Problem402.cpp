/**
 * https://leetcode.com/problems/remove-k-digits/description/?envType=problem-list-v2&envId=stack
 */

#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

/**
 * Solution:
 * Init a stack then loop thru the string, if the current digit > top of the stack, pop it and decrease the k until meet the condition
 * If the k still > 0, pop the stack and decrease k
 * then pop the stack to  a string
 * since it pop from top to bot -> need to reverse the string
 * Remove leading 0 by skip the 0 in that res string until meet condition
 * concat the char from old string to res string after that
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        int left = 0;
        int right = num.length() - 1;
        stack<char> st;
        string res = "";

        for(int i = 0; i < num.length(); i++) {
            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        for(int i = 0; st.size() > 0; i++) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        // remove leading 0
        int idx = 0;
        bool isClearLeadingZero = false;
        string result = "";
        
        for(char& c: res) {
            if(c == '0' && !isClearLeadingZero) {
                continue;
            } else if(c != '0' && !isClearLeadingZero) {
                isClearLeadingZero = true;
            }

            if(isClearLeadingZero) {
                result += c;
            }
        }

        if(result.length() == 1 && result[0] == '0') {
            return res;
        } else if(result.length() == 0) {
            return "0";
        }
        return result;
    }
};

int main(void) {
    Solution sol;
    sol.removeKdigits("10", 3);
}