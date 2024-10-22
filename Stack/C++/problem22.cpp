/**\    
 * https://leetcode.com/problems/daily-temperatures/description/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

/**
 * Solution: init stack to keep track the indice
 * iterate thru all element in the array, check if the value of current indx greater that the value of top index in the stack
 * Then add to the specific index in the res vector with the diff of current index and index in top of the stack
 * So that it can update the number of day for every element in the temparature
 * 
 * after that push the current index to the stack
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size());
        
        for(int i = 0; i < temperatures.size(); i++) {

            while(!st.empty() && temperatures[st.top()] < temperatures[i]) { // check value of current index and index in the top
                int diff = i - st.top(); // since the current i is greater so that every element in the stack will be update the indx
                
                res[st.top()] = diff;

                st.pop();
            }

            st.push(i); // store the index
            
        }
        return res;
    }
};

int main(void) {
    Solution sol;
    vector<int> temp = {73,74,75,71,69,72,76,73};
    sol.dailyTemperatures(temp);
}