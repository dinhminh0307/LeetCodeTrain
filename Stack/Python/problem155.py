class MinStack:
    
    def __init__(self):
        self.stack = []
        self.min_stack = []
        self.min = 0

    def push(self, val: int) -> None:
        if  len(self.stack) == 0:
            self.min = val
            self.min_stack.append(self.min)
        elif self.min >= val:
            self.min = val
            self.min_stack.append(self.min)
        
        self.stack.append(val)

    def pop(self) -> None:
        if len(self.stack) == 0:
            return
        if self.min == self.top():
            if len(self.min_stack) == 0:
                return
            self.min_stack.pop()
            if len(self.min_stack) > 0:
                self.min = self.min_stack[-1]
        self.stack.pop()

    def top(self) -> int:
        if len(self.stack) == 0:
            return
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.min