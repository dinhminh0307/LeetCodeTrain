# Init class in pthon

class Node:
    def __init__(self, val) -> None:
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self, val) -> None:
        new_node = Node(val)
        self.head = new_node
        self.tail = new_node
        self.len = 1
    
    def insertAtBeginning(self, val) -> None:
        new_node = Node(val)
        if self.len == 0:
            self.__init__(val)
            return
        new_node.next = self.head
        self.head = new_node
        self.len += 1
        
    
    def insertAtEnd(self, val) -> None:
        new_node = Node(val)
        if self.len == 0:
            self.__init__(val)
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node
        new_node.next = None
        self.len += 1
    
    def insert(self, val, position) -> None:
        if position < 1:
            return
        new_node = Node(val)
        if self.len == 0:
            self.__init__(val)
            return
        
        if position == 1:
            self.insertAtBeginning(val)
            return
        
        if position >= self.len + 1:
            self.insertAtEnd(val)
            return
        
        temp = self.head
        for i in range(position - 1):
            temp = temp.next
        
        if temp == None:
            return
        new_node.next = temp.next
        temp.next = new_node
        self.len += 1
        
