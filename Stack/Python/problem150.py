class Solution:
    def calculate(self, n1, n2, op):
        if op == "+":
            return n1 + n2
        if op == "-":
            return n1 - n2
        if op == "*":
            # print(n1)
            return n1 * n2
        if op == "/":
            # print(n1 // n2)
            res = n1 / n2
            if res < 0:
                return math.ceil(res)
            return n1 // n2
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for c in tokens:
            if c.lstrip("-").isdigit():
                st.append(int(c))
            else:
                if len(st) < 2:
                    return
                n2 = st.pop()
                n1= st.pop()
                # print("%d %d %d" %(n1, n2, self.calculate(n1, n2, c)))
                st.append(self.calculate(n1, n2, c))
        if len(st) != 1:
            return
        return st[-1]
        