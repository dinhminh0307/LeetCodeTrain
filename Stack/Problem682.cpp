/**
 * https://leetcode.com/problems/baseball-game/description/?envType=problem-list-v2&envId=stack
 */


#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

class Solution {
public:
    bool check_int(string s) {
        for(int  i = 0; i < s.length(); i++) {
            if(s[0] == '-') {
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
    int calPoints(vector<string>& operations) {
        stack<string> st;

        for(auto& c : operations) {
            if(check_int(c)) {
                st.push(c);
            }

            if(c == "C") {
                st.pop();
            } else if(c == "D") {
                int top = stoi(st.top());
                top *= 2;
                st.push(to_string(top));
            } else if(c == "+") {
                int first = stoi(st.top());
                st.pop();
                int second = stoi(st.top());
                int sum = first + second;
                st.push(to_string(first));
                st.push(to_string(sum));
            }
        }

        int res = 0;
        // cout << st.size() << endl;
        while(st.size() > 0) {
            cout << st.top() << endl;
            res += stoi(st.top());
            st.pop();
        }
        return res;
    }
};

int main(void) {
    Solution sol;
    vector<string> s = {"5","2","C","D","+"};
    sol.calPoints(s);
}