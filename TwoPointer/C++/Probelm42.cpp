/**
 * https://leetcode.com/problems/trapping-rain-water/description/
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/**
 * Solution: For every position in the array of height, find the maxium height from each left and right
 * Calculate the capacity in the current position by take min(max_left, max_right) - height[i]
 * Sum up with the area to get total area
 * 
 * O(n) solution:
 * 
 * int trap(vector<int>& height) {
        int block_area = 0;
        unordered_map<int, int> largest;

        for(int i = 0; i < height.size(); i++) {
            if(i == 0 || i == height.size() - 1) {
                continue;
            }

            // take max in the right
            int r = i + 1;
            int max_right = height[r];
            while(r < height.size()) {
                if(height[r] >= max_right) {
                    max_right = height[r];
                }
                if(r == height.size() - 1) {
                    break;
                }
                r++;
            }

            // take max in the left
            int l = i - 1;
            int max_left = height[l];
            while(l >= 0) {
                if(height[l] >= max_left) {
                    max_left = height[l];
                }
                if(l == 0) {
                    break;
                }
                l--;
            }
            // calculate the capacity by take min(l,r) - current position, if(capacity <=0 => 0)
            if(min(max_left, max_right) - height[i] <= 0) {
                continue;
            } else {
                block_area += min(max_left, max_right) - height[i];
            }
        }
        return block_area;
    }
 */

class Solution {
public:
//O(1) Solution
    int trap(vector<int>& height) {
        int block_area = 0;
        unordered_map<int, int> largest;

        int l = 0;
        int r = height.size() - 1;
        int max_left = height[l];
        int max_right = height[r];
        while(l < r) {
            if(max_left < max_right) {
                l++;
                if(max_left - height[l] <= 0) {
                    max_left = height[l]; // if meet any number larger that current max, update the max
                    block_area += 0;
                } else {
                    block_area += max_left - height[l];
                }
                
            } else {
                r--;
                if(max_right - height[r] <= 0) {
                    max_right = height[r];
                    block_area += 0;
                } else {
                    block_area += max_right - height[r];
                }
                
            }
        }
        return block_area;
    }
};

int main(void) {
    Solution sol;
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(nums);
}