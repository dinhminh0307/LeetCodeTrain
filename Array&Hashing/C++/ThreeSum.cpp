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
        unordered_map<int, int> new_nums;
        vector<vector<int>> result;
        

        int idx = 0;
        for(auto& n : nums)
        {
            new_nums.insert({idx, n});
            idx++;
        }

        auto it = new_nums.begin();
        auto tmp = it++;
        for(int i = 0; i < new_nums.size(); i++)
        {
            int a,b,c;
            vector<int> res;
            // Make sure 'it' and 'tmp' are valid before dereferencing to avoid deadly signal
            if (it == new_nums.end() || tmp == new_nums.end()) {
                break;  // Avoid dereferencing invalid iterators
            }

            c = it->second;
            b = tmp->second;
            a = 0 - b - c;
            
            for(auto& f : new_nums)
            {
                if(f.second == a && f.first != it->first && f.first != tmp->first)
                {
                    ostringstream oss;
                    vector<int> res = {a,b,c};
                    
                    // cout << a << " " << b << " " << c << endl;

                    sort(res.begin(), res.end());

                    for(auto& r : res)
                    {
                        oss << r;
                    }
                    string oo = oss.str();
                    auto ss = s.find(oo);
                    if(ss == s.end())
                    {
                        // cout << oo << endl;
                        s.insert(oo);
                    }
                    break;
                }
            }
            // Increment the iterators but ensure they are still valid
            if (++it == new_nums.end()) {
                break;
            }
            if (++tmp == new_nums.end()) {
                break;
            }
        }

        

        for(auto& i: s)
        {
            vector<int> tmp;
            bool is_neg = false;
            for(auto& c : i)
            {
                int n;
                if(c == '-')
                {
                    is_neg = true;
                    continue;
                }
                n = c - '0';
                if(is_neg)
                {
                    n = -n;
                    is_neg = false;
                }
                tmp.push_back(n);
            }
            result.push_back(tmp);
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    vector<int> test = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
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