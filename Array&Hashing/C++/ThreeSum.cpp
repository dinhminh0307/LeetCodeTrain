#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <sstream>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<string> s;
        map<int, int> new_nums;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());


        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0) break; // since in sorted array, when nums[i] > 0, there is no l-r pair that atch
            if(i > 0 &&nums[i] == nums[i- 1]) continue; // avoid duplicate with before

            int left = i + 1;
            int right = nums.size() - 1;
            
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if(sum < 0) {
                    left++;
                } else if(sum > 0) {
                    right--;
                } else {
                    result.push_back({nums[left], nums[right], nums[i]});
                    left++;
                    
                    right--;
                    while(left < right && nums[left] == nums[left - 1]) { // left < right to prevent call the condition when left > right
                        left++;
                    }
                }
            }
        }

        return result;
    }
};

int main(void)
{
    Solution sol;
    vector<int> test = {0,0,0};
    vector<vector<int>> result = sol.threeSum(test);
    for(auto& it : result)
    {
        for(auto& res : it)
        {
            cout << res << " ";
        }
        cout << "\nNext: " << endl;
    }
}