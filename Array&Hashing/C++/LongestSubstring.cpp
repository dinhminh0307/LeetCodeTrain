#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        vector<int> store_max;
        int count = 0;
        if(s.length() == 0) return 0;

        if(s.length() == 1) return 1;

        for(int i = 0; i < s.length(); i++)
        {
            auto it  = m.find(s[i]);
            
            if(it != m.end())
            {
                store_max.push_back(count);
                // cout << count << endl;
                count = 0;
                i = it->second;
                m.clear();
                
            } else {
                count++;
                m.insert({s[i], i});
                store_max.push_back(count);
            }
        }

        return *max_element(store_max.begin(), store_max.end());
    }
};

int main(void)
{
    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s) << endl;
}