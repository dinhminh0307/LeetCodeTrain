/**
 * https://leetcode.com/problems/reverse-integer/description/
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string tmp = to_string(x);
        string ctn = "";
        string res = "";
        bool isZero = false;
        bool isNeg = false;
        if(x / 10 == 0) {
            return x;
        }
        // remove - first
        for(auto& c  : tmp) {
            if(c == '-') {
                isNeg = true;
                continue;
            }
            ctn += c;
        }

        if(isNeg) {
            ctn += '-';
        }

        std::reverse(ctn.begin(), ctn.end());

        // remove leading 0
        for(auto& c : ctn) {
            if(c == '0' && !isZero) {
                continue;
            } else if(c != '0' && !isZero) {
                isZero = true;
            }
            res += c;
        }

        // Try to convert the reversed string to an integer
        long long result = stoll(res);  // Use stoll to handle potential overflow

        // Check if the result is within the 32-bit signed integer range
        if (result > INT_MAX || result < INT_MIN) {
            return 0;  // Return 0 in case of overflow
        }
        return result;
    }
};