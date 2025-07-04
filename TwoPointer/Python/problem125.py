class Solution:
    def isPalindrome(self, s: str) -> bool:
        new_str = ''.join(s.split(" "))
        # filter out all the non alphabetical or non digit character
        new_str = ''.join([i.lower() for i in new_str if i.isalpha() or i.isdigit()])
        first = 0
        last = len(new_str) - 1
        # using 2 pointer from the start and last to check if equal
        while first < last:
            if new_str[first] != new_str[last]:
                return False
            first += 1
            last -= 1
        return True
