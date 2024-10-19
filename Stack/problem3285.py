# https://leetcode.com/problems/find-indices-of-stable-mountains/description/

from typing import List


class Solution:
    def stableMountains(self, height: List[int], threshold: int) -> List[int]:
        stack = []
        
        for i in range(0, len(height)) :
            if i > 0  and height[i - 1] > threshold:
                stack.append(i)
        return stack
    
def test_find_stable_mountains():
    # Test case 1 (the example from the problem description)
    height = [1, 2, 3, 4, 5]
    threshold = 2
    expected_output = [3, 4]  # Only mountains at index 3 and 4 are stable
    assert stableMountains(height, threshold) == expected_output, f"Test case 1 failed"

    # Test case 2 (No stable mountains)
    height = [1, 2, 1, 1, 2]
    threshold = 2
    expected_output = []  # No mountains have a height strictly greater than 2 before them
    assert find_stable_mountains(height, threshold) == expected_output, f"Test case 2 failed"

    # Test case 3 (All stable mountains)
    height = [3, 4, 5, 6, 7]
    threshold = 2
    expected_output = [1, 2, 3, 4]  # All mountains from index 1 to 4 are stable
    assert find_stable_mountains(height, threshold) == expected_output, f"Test case 3 failed"

    # Test case 4 (Threshold higher than all values)
    height = [1, 2, 3, 4, 5]
    threshold = 10
    expected_output = []  # None of the previous heights exceed threshold
    assert find_stable_mountains(height, threshold) == expected_output, f"Test case 4 failed"

    # Test case 5 (Single mountain, no stable mountain)
    height = [5]
    threshold = 2
    expected_output = []  # Only one mountain, no stable mountains possible
    assert find_stable_mountains(height, threshold) == expected_output, f"Test case 5 failed"
    
    print("All test cases passed!")

# Run the test function
test_find_stable_mountains()
   