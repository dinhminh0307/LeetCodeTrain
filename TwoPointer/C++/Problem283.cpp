/**
 * https://leetcode.com/problems/move-zeroes/?envType=problem-list-v2&envId=two-pointers
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int ctr = 0;

        while(left < right && nums.size() > 0) {
            if(nums[left] == 0 && nums.size() > 0) {
                nums.erase(nums.begin() + left);
                ctr++;
                right--;
            } else {
                left++;
            }
            
            
        }
        // for(auto& i : nums) {
        //     cout << i << endl;
        // }
        for(int  i = 0; i < ctr; i++) {
            nums.push_back(0);
        }
        return nums;
    }
};

int main(void) {
    Solution sol;
    vector<int> num = {1,0,0};
    vector<int> res = sol.moveZeroes(num);
    for(auto& it: res) {
        cout << it << endl;
    }
}