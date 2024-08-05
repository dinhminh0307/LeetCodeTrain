#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        if(nums.size() == 1) return false;
        unordered_set<int> s; // using unoredered_set we can store key without concerning about the order
        for(int i = 0; i < nums.size(); i++)
        {
            if(s.find(nums[i]) != s.end()) // if has found nums[i], the find will equal to end
            {
                return true;
            }

            s.insert(nums[i]); // insert the not equal element to the unordered set
        }

        return false;
    }
};

int main(void)
{
    Solution sol;
    vector<int> v = {1,2,3,4, 1};
    if(sol.hasDuplicate(v))
    {
        cout <<"Has duplicate";
    } 
}
