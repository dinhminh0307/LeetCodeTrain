# https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/1430542736/

import random
class RandomizedSet:

    def __init__(self):
        self.bucket = []


    def insert(self, val: int) -> bool:
        if val in self.bucket:
            return False
        
        self.bucket.append(val)
        return True

    def remove(self, val: int) -> bool:
        if len(self.bucket) == 0 or val not in self.bucket:
            return False
        
        self.bucket.remove(val)
        return True

    def getRandom(self) -> int:
        # Logic: choose the randome from the list
        return random.choice(self.bucket)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()