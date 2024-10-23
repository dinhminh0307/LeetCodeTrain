from collections import Counter

# https://leetcode.com/problems/maximum-frequency-stack/
class FreqStack:

    def __init__(self):
        self.bucket = []
        self.map= Counter()

    def push(self, val: int) -> None:
        self.bucket.append(val)
        self.map[val] = self.map[val] + 1

    def pop(self) -> int:
        if len(self.bucket) == 0:
            return -1
        max_freq = max(self.map.values()) # Get the maximum frequency
        for i in range(len(self.bucket) - 1, -1, -1):
            if self.map[self.bucket[i]] == max_freq: #if find the max freq , delete its index in the stack
                val = self.bucket[i]
                self.bucket.pop(i)
                self.map[val] -= 1
                # If the frequency becomes zero, remove the element from the frequency map
                if self.map[val] == 0:
                    del self.map[val]
                return val
        return -1   #if can not find the max freq
        


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()