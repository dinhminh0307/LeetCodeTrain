/**
 * https://leetcode.com/problems/car-fleet/description/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int>& c1, pair<int,int>& c2) {
        return c1.first < c2.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        vector<double> time;
        vector<pair<int,int>> p;

        for(int i = 0; i < position.size(); i++) {
            p.push_back({position[i], speed[i]});
        }
         // Step 2: Sort cars by position in ascd order
        sort(p.begin(), p.end(), cmp);
        
        for(int i = p.size() - 1; i >= 0; i--) {
            double duration = (double) (target - p[i].first) / p[i].second;
            if(!st.empty() && st.top() >= duration) {
                // If the current car's time is less than or equal to the last fleet's time,
                // it will catch up with the fleet, so we do nothing (no new fleet).
                continue;
            }
            st.push(duration);
        }
        
        
        return st.size();
    }
};

int main(void) {
    Solution sol;
    vector<int> position = {6,8};
    int target = 10;
    vector<int> speed = {3,2};
    sol.carFleet(target, position, speed);
}