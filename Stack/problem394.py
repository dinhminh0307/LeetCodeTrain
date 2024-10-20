#https://leetcode.com/problems/decode-string/description/

# Solution: use stack to keep track the char in the string, and continue to push to the string until it meet ']
# If it meet ], pop it char by char to get the string inside it
# after that pop it char by char to find the frequent of it
# then concat thru the string then push to the stack. For example: for the case of "3[a2[c]]", stack 3[a2[c will be come 3,[, a, cc 
# and then continue to do that until the stack will have string only: 

class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for i in range(0, len(s)):
            if s[i] != ']':
                stack.append(s[i])
            else:
                my_str = ""
                while len(stack) > 0 and stack[-1] != '[':
                    my_str = stack[-1] + my_str # place top first so that the string is actually reversed
                    stack.pop()
                    
                if stack[-1] == '[':
                    stack.pop()
                num = ""
                while len(stack) > 0 and stack[-1].isdigit():
                    num = stack[-1] + num 
                    stack.pop()
                
                 # Step 3: Repeat the my_str 'num' times
                stack.append(int(num) * my_str) # push to stack bto handle case nested ], since 3[a2[c]] will be come 3[acc in the stack and to concat them, pop the stack and push until stack
                #contains only string which is the final result
        return ''.join(stack) # concat the stack as the string

                
sol = Solution
sol.decodeString(sol, "3[a2[c]]")