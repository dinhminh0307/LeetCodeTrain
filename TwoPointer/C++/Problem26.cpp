#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if(nums.size() == 1) return 1;
        vector<int>res;
        for(int i = 0; i < nums.size(); i++)
        {
            res.push_back(nums[i]);
            while(i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                i++;
                continue;
            }
        }

        nums.clear();
        for(auto& it: res) {
            cout << it << endl;
            nums.push_back(it);
        }
        // sort(nums.begin(), nums.end());
        return res.size();
    }
};

int main(void)
{
    Solution sol;
    vector<int> num = {1,2,2};
    sol.removeDuplicates(num);
}