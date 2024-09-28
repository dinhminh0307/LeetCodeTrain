#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <vector>

using namespace std;

/**
 * idea: sort first and then put this on to a set , increment the counter to find the corresponding value
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> m;
        vector<int> result;
        map<int, set<int>> store;
        if(nums.empty()) return 0;
        // sort(nums.begin(), nums.end());
        for(auto& it: nums)
        {
            auto f = m.find(it);
            if(f != m.end())
            {
                continue;
            } else {
                m.insert(it);
            }
        }


        auto idx = m.begin();
        int i = *idx; // get the specific index 0 in the set
        int count = 0;
        int end_count = 0;
        while(end_count <= m.size())
        {
            auto it = m.find(i);
            // cout << "ok" << endl;
            if(it == m.end())
            {
                // i = 2, idx =3
                // idx++;
                i = *idx;
                result.push_back(count);
                if(idx == m.end()) break;
                count = 0;
            } else {
                count++;
                end_count++;
                idx++;
                i++;
            }
            
        }
        return *max_element(result.begin(), result.end());
    }
};

int main(void)
{
    Solution sol;
    vector<int> test = {0,3,2,5,4,6,1,1};
    int result = sol.longestConsecutive(test);

    cout << result << endl;
}