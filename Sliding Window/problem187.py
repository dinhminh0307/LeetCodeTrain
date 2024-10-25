from typing import List

# This code defines a solution for finding all the repeated DNA sequences (substrings of length 10) 
# in a given string 's'. The function returns a list of these repeated sequences.
#
# 1. First, it initializes an empty set `store` to keep track of the 10-letter-long sequences that
#    have been seen, and an empty list `res` to store the final results of repeated sequences.
# 2. If the length of the input string 's' is less than or equal to 10, it returns an empty list
#    immediately because no sequence can be repeated.
# 3. It initializes a variable `txt` as the first 10 characters of the input string `s` and adds it to `store`.
#    It also initializes `right` to 10, which represents the next character's index to be checked.
# 4. A loop is started from `left = 0` to the length of s. This ensures that only valid 
#    10-letter substrings are considered.
# 5. For each step of the loop:
#    - If `left` is 0, it skips the logic to extract a new substring because the first substring is already stored.
#    - It sets `txt` as the substring from index `left` to `right` (which is always 10 characters long).
#    - If `txt` is already in `store`, it checks if it's not already in `res`, and if so, adds it to `res`. 
#      It then removes the sequence from `store` to avoid counting it again.
#    - If `txt` is not in `store`, it adds the current sequence to `store`.
#    - `right` is incremented to slide over to the next 10-character substring.
# 6. At the end, if the entire string `s` is somehow added to `res`, it returns an empty list instead 
#    of `res`.
# 7. Finally, the list `res` containing all repeated DNA sequences is returned.

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        store = set()
        res = []
        if len(s) == 1:
            return res
        txt = s[0:10] # first store the first 10 len substring to the store which is then be compared 
        right = 10
        store.add(txt)
        for left in range(0, len(s)): # sliding window, the left will start from 0
            if left == 0: # since the 0 is stored in the store, we dont need to compare now
                right += 1
                continue
            txt = s[left:right] 
            right += 1
            if txt in store: # if we find the duplicate here
                if txt not in res and len(txt) >= 9: # if the len is not 10, dont take it
                    res.append(txt) 
                store.remove(txt)
            else:
                store.add(txt)
        if s in res: # if the current string is not sub string, return empty
            return []
        return res

sol = Solution
sol.findRepeatedDnaSequences(sol, "AAAAAAAAAA")
