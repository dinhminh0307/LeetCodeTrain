from collections import deque
from typing import List


class Node:
    def __init__(self, value) -> None:
        self.value = value
        self.left = None
        self.right = None

class BST:
    def __init__(self) -> None:
       self.root = None

    def insert(self, val) ->bool:
        new_node = Node(val)
        if self.root == None:
            self.root = new_node
            return True
        temp = self.root
        while True:
            if new_node.value == temp.value:
                return False
            if new_node.value < temp.value:
                if temp.left == None:
                    temp.left = new_node
                    break
                else:
                    temp = temp.left
                
            elif new_node.value > temp.value:
                if temp.right == None:
                    temp.right = new_node
                    break
                else:
                    temp = temp.right
        return True

    def contain(self, val) ->bool:
        if self.root == None:
            return False
        temp = self.root

        while True:
            if temp.value == val:
                return True
            if val < temp.value and temp.left == None:
                break
            elif val > temp.value and temp.right == None:
                break
            if val  < temp.value:
                temp = temp.left
            elif val > temp.value:
                temp = temp.right
        return False
    
    def BFS(self) -> List[int]:
        queue = deque()
        res = []
        if not self.root:
            return res  # Return empty list if root is None
        
        queue.append(self.root)
        while queue:
            current_node = queue.popleft()
            res.append(current_node.value)
            
            if current_node.left:
                queue.append(current_node.left)
            if current_node.right:
                queue.append(current_node.right)
        
        return res
    
    def dfs_pre_order(self) -> List[int]:
        res = []

        def traverse(current_node):
            # Visit the current node and add its value to the result list
            res.append(current_node.value)
            # Example: When current_node is 10, res = [10]

            # Traverse the left subtree
            if current_node.left:
                # Before traversing the left subtree of current_node (e.g., node 5)
                traverse(current_node.left)  # Recursive call with left child
                # After traversing the left subtree, control returns here
                # This is how we return to node 5 after visiting node 2

                # **Explanation of Returning to Node 5 from Node 2:**
                # - When we call traverse(current_node.left), we go deeper into the left subtree.
                # - For node 5, left child is node 2.
                # - We call traverse(2).
                # - Node 2 is visited and added to res: res = [10, 5, 2].
                # - Node 2 has no left or right children, so the function returns.
                # - Control goes back to the point after traverse(2) call in traverse(5).
                # - This is how we "go back" to node 5 after finishing with node 2.

            # Traverse the right subtree
            if current_node.right:
                # Before traversing the right subtree of current_node (e.g., node 7)
                traverse(current_node.right)  # Recursive call with right child
                # After traversing the right subtree, control returns here

        # Start the traversal from the root node
        traverse(self.root)
        return res


       

bst = BST()
bst.insert(10)
bst.insert(5)
bst.insert(15)
bst.insert(2)
bst.insert(7)
bst.insert(12)
bst.insert(17)

print(bst.dfs_pre_order())  # Expected output in BFS order: [10, 5, 15, 2, 7, 12, 17]
