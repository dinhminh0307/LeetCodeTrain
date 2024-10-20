#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> stringSequence(string target) {
        string tmp = "";
        stack<char> target_q;
        stack<char> tmp_q;
        vector<string> res;
        bool isReplaced = false;
        for(char& c : target) {
            target_q.push(c);
        }

        while(tmp != target) {
            if(tmp.length() < target.length()) {
                tmp += 'a';
                tmp_q.push('a');
            }
            res.push_back(tmp);

            while(!tmp_q.empty() && !target_q.empty() && tmp_q.top() != target_q.top()) {
                char s = tmp_q.top() + 0x01;
                tmp_q.pop();
                tmp_q.push(s);
                tmp[tmp.length() - 1] = s;
                res.push_back(tmp);
                isReplaced = true;
            }

            if(!tmp_q.empty()) {
                tmp_q.pop();
            }
        }
        return res;
    }
};