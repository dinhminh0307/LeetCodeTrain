#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Comparator function to sort pairs 
// according to second value 
bool cmp(pair<int, int>& a, 
        pair<int, int>& b) 
{ 
    return a.second > b.second; 
} 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> order;
        if(nums.size() == 1) return nums;

        for(auto &s: nums)
        {
            int count = 1;
            auto it = order.find(s);
            if(it != order.end())
            {
                it->second++;
            } else {
                order.insert({s, count});
            }
        }

        vector<pair<int, int>> v;

        for(auto &s : order)
        {
            v.push_back(s); // push back the key-value element in order to vector pair
        }

        sort(v.begin(), v.end(), cmp);// Sort using comparator function 
        
        vector<int> result;
        int counter = 1;
        for(auto &s: v)
        {
            result.push_back(s.first);
            if(counter == k) return result;
            counter++;
        }
        return result;
    }
};


int main(void)
{
    Solution sol;
    vector<int> dat = {7,7};
    vector<int> printedResult = sol.topKFrequent(dat, 1);

    for(auto &m : printedResult)
    {
        cout << m << endl;
    }
}
