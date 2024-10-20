#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to return all divisors of a number
    vector<int> getDivisors(int x) {
        vector<int> divisors;
        for (int i = 1; i <= x / 2; ++i) {
            if (x % i == 0) {
                divisors.push_back(i);
            }
        }
        divisors.push_back(x); // Add the number itself
        return divisors;
    }

    // Function to calculate the minimum number of operations to make the array non-decreasing
    int numberOfOperations(vector<int>& nums) {
        int operations = 0;

        // Traverse from the second last element to the first
        for (int i = nums.size() - 2; i >= 0; --i) {
            // If current element is greater than the next
            if (nums[i] > nums[i + 1]) {
                vector<int> divisors = getDivisors(nums[i]);

                bool found = false;
                for (int d = divisors.size() - 1; d >= 0; --d) {
                    if (divisors[d] <= nums[i + 1]) {
                        nums[i] = divisors[d];  // Set nums[i] to the largest valid divisor
                        ++operations;  // Increment operation count
                        found = true;
                        break;
                    }
                }

                // If no valid divisor found, return -1 (impossible case)
                if (!found) {
                    return -1;
                }
            }
        }

        return operations;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {105, 11};  // Test case

    int result = solution.numberOfOperations(nums);

    cout << "Minimum number of operations: " << result << endl;

    return 0;
}
