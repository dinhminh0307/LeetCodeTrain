class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        store = str(num)
        tmp = []
        count = 0
        for c in store:
            tmp.append(c)
        
        for left in range(len(tmp)):
            right = left + k
            if right > len(tmp):
                break
            temp = tmp[left: right]
            # print(f"{left} {right}")
            s = ''.join(temp)
            n = int(s)
            
            if n != 0 and num % n == 0:
                print(f"{n} {num} left: {left} right: {right}")
                count += 1
        return count
            
sol = Solution
sol.divisorSubstrings(sol, 30003, 3)

