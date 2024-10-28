class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m1 = {}
        m2 = {}
        # push s1 in a hash table
        for c in s1:
            m1[c] = m1.get(c, 0) + 1
        # iterate thru the s2 to find the character in that hash table
        left  = 0
        len_count = 0
        for right in range(len(s2)):
            current_char = s2[right]
            if current_char in m1:
                m2[current_char] = m2.get(current_char, 0) + 1
                 # Shrink the window if it exceeds the length of s1
                while (right - left + 1) > len(s1):
                    left_char = s2[left]
                    #However, when the window exceeds the size of s1, we need to shrink the window from the left (left pointer) to ensure that the window size stays equal to len(s1).
                    if left_char in m2:
                        # If you don't decrement m2[left_char], 
                        # the map will incorrectly track characters that are no longer in the window, leading to inaccurate frequency counts. This would cause the comparison of m2 with m1 to fail.
                        m2[left_char] -= 1
                        if m2[left_char] == 0:
                            del m2[left_char]
                    left += 1
                    # if in the sequence string continiously, m1 = m2 so that it return true
                if m1 == m2:
                    return True
            else:
                # If the character is not in s1, reset the window
                m2.clear()
                left = right + 1

        return False
            
sol = Solution
sol.checkInclusion(sol, "abc", "bbbca")