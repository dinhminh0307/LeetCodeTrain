#include <iostream>
#include <vector>
#include <bits/stdc++.h>

/*
SOlution: put them all in a hash map, key: the element itself, val: index of that element since unordered does not care about index
then compare the element with target - vector[index] to find the desired value
*/

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> v;
        vector<int> final_result;
        if(nums.size() == 1)
        {
            vector<int> result;
            if(target == nums[0])
            {
                result = {0,0};
                return result;
            } else {
                return result;
            }
            
        }
        for(int i = 0; i < nums.size(); i++)
        {
            v.insert({nums[i], i});
        }

        for(int i = 0; i < nums.size(); i++)
        {
            auto it = v.find(target - nums[i]);
            if(it != v.end())
            {
                if(it->second == i) continue;

                final_result.push_back(i);
                final_result.push_back(it->second);
                return final_result;
            }
        }
        return final_result;
    }
};

int main(void)
{
    Solution sol;
    vector<int> input = {3,3};
    vector<int> printedResult = sol.twoSum(input, 6);
    for(int i = 0; i < printedResult.size(); i++)
    {
        cout << printedResult[i] << endl;
    }
}

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp; 

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            mp.insert({nums[i], i});
        }
        return {};
    }
};
*/