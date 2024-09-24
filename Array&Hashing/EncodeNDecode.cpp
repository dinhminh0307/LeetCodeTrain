#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        int ctr = 0;
        if(strs.size() == 0) return "null";
        for(auto &s: strs)
        {
            result += s;
            if(ctr == strs.size() -1) break;
            result += "|";
            ctr++;
        }
        return result;
    }

    vector<string> decode(string s) {
        stringstream ss(s); //using string stream to split the character
        vector<string> results;
        string token;
        char delimiter = '|';
        if(s == "null") return results;
        if(s.length() == 0) 
        {
            results.push_back("");
            return results;
        }
        while (getline(ss, token, delimiter)) // using string strea,
        {
            results.push_back(token);
        }
        return results;
    }
};

int main(void)
{
    vector<string> s = {""};
    Solution sol;
    string decoded_char = sol.encode(s);
    cout << decoded_char.length() << endl;
    vector<string> result = sol.decode(decoded_char);
    for(auto &it : result)
    {
        cout << it << endl;
    }
}