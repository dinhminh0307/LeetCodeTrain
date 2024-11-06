class Node:
    def __init__(self, value) -> None:
        self.value = value
        self.left = None
        self.right = None

class BST:
    def __init__(self) -> None:
       self.root = None

    def insert(self, val) ->None:
        new_node = Node(val)
        if self.root == None:
            self.root = new_node
            return
        temp = self.root
        while True:
            if new_node.value == temp.value:
                return False
            if new_node.value < temp.value and temp.left == None:
                temp.left = new_node
                break
            elif new_node.value > temp.value and temp.right == None:
                temp.right = new_node
                break
            if new_node.value < temp.value:
                temp = temp.left
            elif new_node.value > temp.value:
                temp = temp.right

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
            