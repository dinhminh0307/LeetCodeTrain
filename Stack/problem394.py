class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        my_str = ""
        for i in range(len(str)):
            while str[i].isdigit():
                my_str += str[i]

                
