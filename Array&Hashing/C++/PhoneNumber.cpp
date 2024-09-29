#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=problem-list-v2&envId=hash-table
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> m;
        set<char> combine;
        vector<string> result;
        if(digits.length() == 0) return result;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        result.push_back(""); // this will be used as an container to concat string char by char
        for(auto &num : digits) // loop thru digit
        {
            vector<string> tmp;
            for(auto& str : result) // concat the string and store in the result for each digit
            {
                for(auto& c: m[num])
                {
                    tmp.push_back(str + c); // update the conat string to tmp vector
                }
            }

            result.swap(tmp); // swap between tmp and result. So that tmp is {a,b,c} and tmp is {""}
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    sol.letterCombinations("23");
}
