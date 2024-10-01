#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
          merged.begin());

        int n = merged.size();
        if (n % 2 != 0) {
            return merged[n / 2];
        } else {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }

    }
};

int main(void)
{
    Solution sol;
    vector<int> num1 = {1,3};
    vector<int> num2 = {2,4};
    cout << sol.findMedianSortedArrays(num1, num2); 
}   