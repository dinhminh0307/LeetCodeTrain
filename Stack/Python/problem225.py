class MyStack:

    def __init__(self):
        self.bucket = []

    def push(self, x: int) -> None:
        self.bucket.append(x)

    def pop(self) -> int:
        if len(self.bucket) == 0:
            return 0
        res = self.bucket[-1]
        del(self.bucket[-1])
        return res

    def top(self) -> int:
        if len(self.bucket) == 0:
            return 0
        return self.bucket[-1]

    def empty(self) -> bool:
        if len(self.bucket) == 0:
            return True
        return False


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()