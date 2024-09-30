#include <iostream>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> m;
        auto it = nums.begin();
        // filter out negtive
        for(int i = 0; i < nums.size(); i++)
        {
            m.insert(nums[i]);
            it++;
        }   

        if(nums.size() == 0) return 1;

        int idx = 1;
        while(1)
        {
            auto it = m.find(idx);
            if(it == m.end())
            {
                return idx;
            } else {
                idx++;
            }
        }
        return 0;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {1,2,0};
    int num = sol.firstMissingPositive(nums);
    cout << num << endl;
}