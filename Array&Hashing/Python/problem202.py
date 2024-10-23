class Solution:
    """
    This function determines whether a given number 'n' is a happy number.
    
    A happy number is defined as a number that eventually reaches 1 when 
    replaced by the sum of the squares of its digits repeatedly. If the 
    process ends up in a cycle (i.e., if a number repeats during the process), 
    then the number is not a happy number.
    
    - The function uses a set 's' to track all numbers encountered during 
      the process. This helps detect cycles.
    - For each number 'n', it calculates the sum of the squares of its digits.
    - If 'n' becomes 1, the number is happy, and the function returns True.
    - If 'n' is already in the set 's', it means a cycle has been detected, 
      so the function returns False.
    - Otherwise, the process continues until either a cycle is found or 'n' 
      becomes 1.
    """
    def isHappy(self, n: int) -> bool:
        
        s = set() # keep track every number we encounter
        while n != 1:
            sum = 0
            if n not in s:
                s.add(n)
            else:
                return False
            num_str = str(n)
            for i in num_str:
                sum += int(i) ** 2
            n = sum
        return True