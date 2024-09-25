#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        map<int, int> m;
        vector<int> result;

        int prefix[nums.size()];
        int postfix[nums.size()];
        for(int i = 1; i < nums.size(); i++)
        {
            prefix[0] = nums[0];
            prefix[i] = prefix[i - 1] * nums[i];
        }
    
        // calculate postfix
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            postfix[nums.size() - 1] = nums[nums.size() - 1];
            postfix[i] = postfix[i + 1] * nums[i];
        }


        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0)
            {
                result.push_back(postfix[i + 1]);
            } else if(i == nums.size() - 1)
            {
                result.push_back(prefix[i - 1]);
            } else {
                result.push_back(prefix[i - 1] * postfix[i + 1]);
            }
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {0, 0};
    vector<int> result = sol.productExceptSelf(nums);
    // cout << result.size();
    for(auto& i : result)
    {
        cout << i << endl;
    }
}