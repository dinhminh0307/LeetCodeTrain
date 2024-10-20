class Solution:
    # Helper function to perform DFS from the root node, building the path dynamically
    def dfs(self, node, s, tree, path, answer):
        # Add current node's character to the path
        path.append(s[node])

        # Check if the current path is a palindrome
        if self.isPalindrome(path):
            answer[node] = True
        else:
            answer[node] = False

        # Traverse all children of the current node
        for child in tree[node]:
            self.dfs(child, s, tree, path, answer)

        # Backtrack: remove the current node's character when returning to the parent
        path.pop()

    # Helper function to check if a string is a palindrome
    def isPalindrome(self, path):
        left = 0
        right = len(path) - 1
        while left < right:
            if path[left] != path[right]:
                return False
            left += 1
            right -= 1
        return True

    # Main function to find the answer for each node
    def findAnswer(self, parent, s):
        n = len(s)

        # Build the tree from the parent array
        tree = [[] for _ in range(n)]
        for i in range(1, n):
            tree[parent[i]].append(i)

        # Result array to store if the path from the root to each node is a palindrome
        answer = [False] * n

        # Start DFS from the root (node 0)
        path = []
        self.dfs(0, s, tree, path, answer)

        return answer

# Example usage:
parent = [-1, 0, 0, 1, 1, 2]
s = "aababa"
sol = Solution()
result = sol.findAnswer(parent, s)

# Printing the result
print(result)
