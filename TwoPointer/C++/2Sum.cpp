#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;

        int left = 0;
        int right = numbers.size() - 1;
        if(numbers.size() == 1 && numbers[0] == target)
        {
            result.push_back(1);
            return result;
        }
        for(int i = 0; i < numbers.size(); i++)
        {
            // cout << numbers[left] << " " << numbers[right] << endl;
            int sum = numbers[left] + numbers[right];
            if(sum < target)
            {
                left++;
            } else if(sum > target) {
                right--;
            } else if(sum == target)
            {
                left++;
                right++;
                result.push_back(left);
                result.push_back(right);
                return result;
            }
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    vector<int> num = {1};
    vector<int> result = sol.twoSum(num, 1);
    for(auto &it : result)
    {
        cout << it << endl;
    }
}