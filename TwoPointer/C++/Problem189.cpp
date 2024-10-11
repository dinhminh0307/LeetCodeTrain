/**
 * https://leetcode.com/problems/rotate-array/description/?envType=problem-list-v2&envId=two-pointers
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;

        while(k > 0) {
            nums.insert(nums.begin() + l, nums[r]);
            r--;
            k--;
            if(r == l) break;
        }
        return nums;
    }
};

int main(void) {
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    vector<int> result = sol.rotate(nums, k);
    for(auto& it : result) {
        cout << it << endl;
    }
}