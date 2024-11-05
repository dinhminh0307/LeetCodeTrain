#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        bool isFound = false;

        while(fast <= nums.size()) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(fast == slow) { // the node that fast and slow intersect with each other
                isFound = true; // to find the intersection
                break;
            }
        }

        // take a slow pointer at head again and increment when 2 slow pointer intersects again
        int slow2 = 0;
        // with isFound, when the array is linear, it wont call the loop again
        while(isFound &&  slow2 <=nums.size()) {
            slow = nums[slow];
            slow2 = nums[slow2];

            if(slow == slow2) {
                return slow;
            }
        }
        return -1;
    }
};