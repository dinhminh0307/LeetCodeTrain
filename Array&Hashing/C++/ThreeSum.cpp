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
        map<int, int> new_nums;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        int idx = 0;
        for(auto& n : nums)
        {
            new_nums.insert({idx, n});
            idx++;
        }

        // auto be = new_nums.begin();
        // for(int i = 0; i < new_nums.size(); i++)
        // {
        //     cout << be->second << endl;
        //     be++;
        // }

        auto it = new_nums.begin();
        auto tmp = new_nums.rbegin(); // start from end
        auto sum = new_nums.begin();

        /*Logic: 2 pointers techinique*/
        bool isFound = false;
        while(true)
        {
            
            if(sum == it)
            {
                it++;
                continue;
            }

            if(tmp->first == sum->first)
            {
                tmp++;
                continue;
            }

            // if(tmp->first == it->first)
            // {
            //     tmp++;
            //     it++;
            //     cout << "new: " << tmp->second << " " << it->second << endl; 
            //     continue;
            // }

            int some = it->second + tmp->second;
            cout << it->second << " " << tmp->second<< " " << -sum->second << " " << some << endl;
            if(some < -sum->second)
            {
                if(it == new_nums.end())
                {
                    it = new_nums.begin();
                    tmp = new_nums.rbegin();
                    sum++;
                    continue;
                }
                it++;
                continue;
            } else if(some > -sum->second) {
                if(tmp == new_nums.rend())
                {
                    it = new_nums.begin();
                    tmp = new_nums.rbegin();
                    sum++;
                    continue;
                }
                tmp++;
                continue;
            } else if(some == -sum->second) {
                vector<int> res = {it->second, tmp->second, sum->second};
                sort(res.begin(), res.end());
                cout << "ok" << endl;
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
                    it = new_nums.begin();
                    tmp = new_nums.rbegin();
                    sum++;
                } else {
                    it++;
                    tmp++;
                }
                
            }

            // Break condition to prevent infinite loops
            if (it == new_nums.end() && tmp == new_nums.rend()) {
                break;
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
    vector<int> test = {-1,0,1,2,-1,-4};
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