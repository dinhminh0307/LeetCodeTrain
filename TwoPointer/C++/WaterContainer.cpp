#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/**
 * Idea: instead of extending the width, try to increase the height of 2 column since the gap of the width to the height is fixed
 * then we can update the 2 pointers base on the height
 */

class Solution {
public:
    int calculateArea(int num1, int num2, int gap)
    {
        if(num1 < num2) return num1 * gap;
        return num2 * gap;
    }

    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxium = calculateArea(heights[left], heights[right], heights.size() - 1 - left);
         

        while(left < right)
        {
            int area = calculateArea(heights[left], heights[right], right - left);
            if(area > maxium)
            {
                maxium = area;
            }
            if(heights[left] <= heights[right])
            {
                
                left++;
            } else {
                right--;
            } 
            cout << left << " " << right << endl;
        }
        return maxium;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {1,7,1,1,1,1,2,5,12,3,500,50,7,8,4,7,38,9,10,12,6};
    cout << sol.maxArea(nums) << endl;
}
