class Solution:

#     Syntax: dict.get(key, default_value)
# If the key exists in the dictionary, it returns the corresponding value.
# If the key does not exist, it returns the default_value.

# Solution: start the window from the left of the string, for each character, store them to the hashmap to count the frequency
#     for a substring with high frewuency for example: "ABAA", we need to compare with k the number of replacement by: left- right + 1 - max_frequency
#     if the number of replacement still not statisfy, extend the window to the right and update the max substring until it satisfy the condition
#     once it satisfy the condition, shrink the window from the left to find the other substring as well
    def characterReplacement(self, s: str, k: int) -> int:
        m = {}
        left = 0
        res = 0 # keep track the longest substring found
        maxf = 0 # keep track of the max frequent
        for right in range(len(s)):
            m[s[right]] = m.get(s[right], 0) + 1
            maxf = max(m[s[right]], maxf) ## update date the max frequenet of character
            while (right - left + 1) - maxf > k: ## length - most freq char in substring to know how many char needed to be replaced
                # shrink the window to start a new window
                m[s[left]] -= 1
                left += 1
            res = max(res, right - left + 1) # update the max length of the window
        return res
            
            
                