class Node:
    def __init__(self, value) -> None:
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self, value) -> None:
        new_node = Node(value)
        self.head = new_node
        self.tail = new_node
        self.length = 1
    
    def insertAtBeginning(self, value) -> None:
        new_node = Node(value)
        if self.length == 0:
            self.__init__(value)
            return
        new_node.next = self.head
        self.head = new_node
        self.length += 1
        
    
    def insertAtEnd(self, value) -> None:
        new_node = Node(value)
        if self.length == 0:
            self.__init__(value)
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node
        new_node.next = None
        self.length += 1
    
    def insert(self, value, position) -> None:
        if position < 1:
            return
        new_node = Node(value)
        if self.length == 0:
            self.__init__(value)
            return
        
        if position == 1:
            self.insertAtBeginning(value)
            return
        
        if position >= self.length + 1:
            self.insertAtEnd(value)
            return
        
        temp = self.head
        for i in range(position - 1):
            temp = temp.next
        
        if temp == None:
            return
        new_node.next = temp.next
        temp.next = new_node
        self.length += 1