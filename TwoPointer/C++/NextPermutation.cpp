#include <iostream>
#include <vector>
#include <algorithm> // Use <algorithm> instead of <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Find the first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Find the element just larger than nums[i]
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // Swap them
            swap(nums[i], nums[j]);
        }

        // Sort the elements from i+1 to the end of the array
        sort(nums.begin() + i + 1, nums.end());

        return nums;
    }
};


int main(void)
{
    Solution sol;
    vector<int> nums = {4,3,2,1};
    vector<int> res = sol.nextPermutation(nums);
    for(auto& i : res)
    {
        cout << i << endl;
    }
}