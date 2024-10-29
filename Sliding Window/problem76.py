# https://leetcode.com/problems/minimum-window-substring/description/

class Solution:
    def minWindow(self, s: str, t: str) -> str:
         # Step 1: Create a frequency map 'm1' for characters in the string 't'.
        m1 = {}
        for c in t:
            m1[c] = m1.get(c, 0) + 1
        left  = 0
        m2 = {} # This will store the character frequency of the current window in 's'.
        stack = [] # This stores the result (smallest window substring).
        min_len = len(s) + 1
        stack.append("")
         # Step 2: Use a sliding window technique with the 'right' pointer.
        for right in range(len(s)):
            isIncluded = False # Flag to check if all characters from 't' are included in the current window.
            if s[right] in m1:
                m2[s[right]] = m2.get(s[right], 0) + 1 # Step 3: If the character at 'right' in 's' exists in 'm1', update the frequency in 'm2'.
                
            # Step 4: Check if all characters of 't' are included in the window.
            # This is done by comparing frequencies of characters in 'm1' and 'm2'.
            for temp in m1:
                if temp not in m2 or m2[temp] < m1[temp]:
                    isIncluded = True  # If any character in 't' is missing or its frequency is insufficient, set 'isIncluded' to True.
                    break
                # Step 5: If not all characters are included, continue expanding the window. to the right
            if isIncluded:
                continue
            else:
                 # Step 6: When all characters are included, try shrinking the window from the left.
                while s[left] not in m1 or (m2[s[left]] > m1[s[left]]):
                    if s[left] in m2:
                        m2[s[left]] -= 1
                    left += 1
                    
                # Step 7: Update the smallest window if the current window is smaller than the previous one.
                if right - left + 1 <= min_len:
                    min_len = right - left + 1
                    stack = [s[left:right + 1]]  # Update the result in stack
                
# Step 8: Return the smallest window substring stored in 'stack'.
        return stack[0]

sol = Solution
sol.minWindow(sol,"acbbaca","aba")
