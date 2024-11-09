class Node:
    def __init__(self, value) -> None:
        self.value = value
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self, value) -> None:
        new_node = Node(value)
        self.head = new_node
        self.tail = new_node
        self.length = 1

    def print_list(self) -> None:
        temp = self.head
        while temp and temp.next:
            print(temp.val)
            temp = temp.next

    def append(self, val)-> bool:
        new_node = Node(val)
        if self.head == None and self.tail == None:
            self.head = new_node
            self.tail = new_node
            self.length = 1
            return True
        # the last node point to new node
        self.tail.next = new_node
        #the new node prev to last node
        new_node.prev = self.tail
        # set tail to new node
        self.tail = new_node
        
        self.length += 1
        return True 