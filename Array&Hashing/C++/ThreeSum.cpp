#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> decode(string s) {
        stringstream ss(s); //using string stream to split the character
        vector<string> results;
        string token;
        char delimiter = '#';
        if(s == "null") return results;
        if(s.length() == 0) 
        {
            results.push_back("");
            return results;
        }
        while (getline(ss, token, delimiter)) // using string strea,
        {
            results.push_back(token);
        }
        return results;
    }

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
        auto tmp = it;
        /*Logic: it will start from 0 and tmp will run till end of the list without no interupt it
        if tmp run over the list, increment the it and tmp will start over again except it position
        it will be assign to c, tmp assign to b. so just need to find a*/
        while (it != new_nums.end()) {
            int a, b, c;

            if (tmp == new_nums.end()) {
                // Reset tmp to the beginning when reaching the end of the list
                tmp = new_nums.begin();
                it++;  // Move 'it' to the next element
                continue;
            }

            if (it == new_nums.end()) {
                // Exit the loop if 'it' has reached the end
                break;
            }

            // Make sure 'tmp' is not equal to 'it'
            if (tmp == it) {
                tmp++;
                continue;
            }

            // Extract values from the iterators
            c = it->second;
            b = tmp->second;
            a = 0 - b - c;

            unordered_set<int> seen;
            for (auto& f : new_nums) {
                if (f.first != it->first && f.first != tmp->first) {
                    if (seen.find(a) != seen.end()) {
                        // If we find a valid triplet (a, b, c), process it
                        vector<int> res = {a, b, c};

                        // Sort the triplet for uniqueness
                        sort(res.begin(), res.end());

                        // Create a string from the triplet to store in the set
                        string tmp_str;
                        for (size_t i = 0; i < res.size(); ++i) {
                            tmp_str += to_string(res[i]);
                            if (i != res.size() - 1) {
                                tmp_str += '#';  // Add delimiter between numbers
                            }
                        }

                        // Insert the triplet string into the set if it hasn't been added already
                        if (s.find(tmp_str) == s.end()) {
                            s.insert(tmp_str);
                        }

                        break;  // Break after finding a valid triplet
                    }
                    seen.insert(f.second);  // Add current element to the set for later comparisons
                }
            }

            // Increment the tmp iterator and check for the end
            tmp++;
            if (tmp == new_nums.end()) {
                it++;
                tmp = new_nums.begin();
            }
        }


        for(auto& i: s)
        {
            vector<int> tmp;
            vector<string> tmp_str = decode(i);
            for(string c : tmp_str)
            {
                // cout << c << endl;
                int n = stoi(c);
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