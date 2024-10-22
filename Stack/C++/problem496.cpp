/**
 * https://leetcode.com/problems/next-greater-element-i/description/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

/**
 * Solution: since nums1 is the sub set of nums2, put nums2 in a hash map with the key is the value of element in nums2 O(N)
 * loop thru the nums1, to find the corresponding element in the map (O(N))
 * if found the element, use stack to kleep track the current element to define if it larger than the current element or not
 * if not , continue to heck to the end of nums2. and pop it, if the stack is empty, push back -1
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> res;

        // put the nums2 to the map
        for(int i = 0; i < nums2.size(); i++) {
            m.insert({nums2[i], i});
        }

        for(int& n: nums1) {
            auto it = m.find(n);
            // find next greater element    
            int idx = it->second;
            if(it != m.end() && idx < nums2.size()) {
                stack<int> st;
                for(int i = idx; i < nums2.size(); i++) {
                    st.push(nums2[i]);
                    
                    if(st.top() > nums2[idx]) {
                        res.push_back(st.top());
                        break;
                    } else {
                        
                        st.pop();
                    }
                }
                if(st.empty()) {
                    // cout << "empty" << endl;
                    res.push_back(-1);
                }
            }
        }
        return res; 
    }
};

int main(void) {
    Solution sol;

    vector<int> nums1 = {2,4};
    vector<int> nums2 = {1,2,3,4};

    sol.nextGreaterElement(nums1, nums2);
}