class CustomStack:

    def __init__(self, maxSize: int):
        self.bucket = []
        self.size = maxSize

    def push(self, x: int) -> None:
        if len(self.bucket) == self.size:
            return
        self.bucket.append(x)

    def pop(self) -> int:
        if len(self.bucket) == 0:
            return -1
        return self.bucket.pop()

    def increment(self, k: int, val: int) -> None:
        if k >= len(self.bucket):        
            for i in range(len(self.bucket)):
                self.bucket[i] = self.bucket[i] + val
        else:
            for i in range(0, k):
                self.bucket[i] = self.bucket[i] + val
            



# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)