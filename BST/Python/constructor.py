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

bst = BST()
bst.insert(10)
bst.insert(5)
bst.insert(15)
bst.insert(2)
bst.insert(7)
bst.insert(12)
bst.insert(17)

print(bst.BFS())  # Expected output in BFS order: [10, 5, 15, 2, 7, 12, 17]
