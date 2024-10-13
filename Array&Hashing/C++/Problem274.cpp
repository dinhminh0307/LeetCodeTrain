/**
 * https://leetcode.com/problems/h-index/description/
 */

#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
    //0 1 3 5 6
    // 1 1 3
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        unordered_set<int> s;
        int len = citations.size();
        int max = 0;
        int freq = 0;
        if(len == 1 && citations[0] == 0) {
            return 0;
        }


        for(int i = 0; i < citations.size(); i++) {
            
            int tmp = citations.size() - i;
            int idx = 0;
            auto it = s.find(citations[i]);
            int index = i;
            // while(index < citations.size() - 1 && citations[index] == citations[index + 1]) {
            //     idx++;
            //     index++;
            // }
            
            // if(idx == citations[i] && citations[i] > 0) {
            //     return citations[i];
            // }
            cout << tmp << " " << citations[i] << endl;
            if(tmp <= citations[i]) { // 1 1 3 tmp = 3, 1
                return tmp;
            }
            

        }
        return 0;
    }
};

int main(void) {
    Solution sol;
    vector<int> nums = {1,3,1};
    sol.hIndex(nums);
}