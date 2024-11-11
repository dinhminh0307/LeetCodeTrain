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
        while temp:
            print(temp.value)
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
    
    def pop(self) -> bool:
        if self.tail == None and self.head == None:
            return False
        tmp = self.tail
        # break the connection between 2 nodes
        if tmp.prev:
            tmp.prev.next = None
            self.tail = tmp.prev
            tmp.prev = None
        else:
            self.head = None
            self.tail = None
        self.length -= 1
        return True
    
    def prepend(self, val) -> bool:
        new_node = Node(val)
        if self.head == None and self.tail == None:
            self.append(val)
            return True
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        self.length += 1
        return True
    
    def pop_first(self) -> bool:
        if self.tail == None and self.head == None:
            return False
        if self.length == 1:
            self.pop()
            return True
        tmp = self.head.next
        tmp.prev = None
        self.head.next = None
        self.head = tmp
        self.length -= 1
        return True
        

# Create a DoublyLinkedList instance
# dll = DoublyLinkedList(1)
# print("Initial list after creating with one element:")
# dll.print_list()
# print("Length:", dll.length)
# print("Head:", dll.head.value if dll.head else None)
# print("Tail:", dll.tail.value if dll.tail else None)

# # Append elements to the list
# dll.append(2)
# dll.append(3)
# dll.append(4)

# print("\nList after appending 2, 3, and 4:")
# dll.print_list()
# print("Length:", dll.length)
# print("Head:", dll.head.value if dll.head else None)
# print("Tail:", dll.tail.value if dll.tail else None)

# # Pop elements from the list
# dll.pop()
# print("\nList after first pop (should remove 4):")
# dll.print_list()
# print("Length:", dll.length)
# print("Head:", dll.head.value if dll.head else None)
# print("Tail:", dll.tail.value if dll.tail else None)

# dll.pop()
# print("\nList after second pop (should remove 3):")
# dll.print_list()
# print("Length:", dll.length)
# print("Head:", dll.head.value if dll.head else None)
# print("Tail:", dll.tail.value if dll.tail else None)

# dll.pop()
# print("\nList after third pop (should remove 2):")
# dll.print_list()
# print("Length:", dll.length)
# print("Head:", dll.head.value if dll.head else None)
# print("Tail:", dll.tail.value if dll.tail else None)

# dll.pop()
# print("\nList after fourth pop (should be empty):")
# dll.print_list()
# print("Length:", dll.length)
# print("Head:", dll.head)
# print("Tail:", dll.tail)

# # Prepend elements to the list
# dll.prepend(0)
# print("\nList after prepending 0:")
# dll.print_list()
# print("Length:", dll.length)
# print("Head:", dll.head.value if dll.head else None)
# print("Tail:", dll.tail.value if dll.tail else None)

# dll.prepend(-1)
# print("\nList after prepending -1:")
# dll.print_list()
# print("Length:", dll.length)
# print("Head:", dll.head.value if dll.head else None)
# print("Tail:", dll.tail.value if dll.tail else None)

# # Test prepend on an empty list
# dll.pop()
# dll.pop()
# dll.pop()
# dll.pop()  # Now the list should be empty

# print("\nList after clearing all elements (should be empty):")
# dll.print_list()
# print("Length:", dll.length)
# print("Head:", dll.head)
# print("Tail:", dll.tail)

# # Prepend to an empty list
# dll.prepend(5)
# print("\nList after prepending 5 to an empty list:")
# dll.print_list()
# print("Length:", dll.length)
# print("Head:", dll.head.value if dll.head else None)
# print("Tail:", dll.tail.value if dll.tail else None)

# Initialize a new list
dll = DoublyLinkedList(10)
dll.append(20)
dll.append(30)
dll.append(40)

print("Initial list:")
dll.print_list()
print("Length:", dll.length)
print("Head:", dll.head.value if dll.head else None)
print("Tail:", dll.tail.value if dll.tail else None)

# Test pop_first on a list with multiple elements
dll.pop_first()
print("\nList after first pop_first (should remove 10):")
dll.print_list()
print("Length:", dll.length)
print("Head:", dll.head.value if dll.head else None)
print("Tail:", dll.tail.value if dll.tail else None)

dll.pop_first()
print("\nList after second pop_first (should remove 20):")
dll.print_list()
print("Length:", dll.length)
print("Head:", dll.head.value if dll.head else None)
print("Tail:", dll.tail.value if dll.tail else None)

# Test pop_first on a list with one element
dll.pop_first()
print("\nList after third pop_first (should remove 30):")
dll.print_list()
print("Length:", dll.length)
print("Head:", dll.head.value if dll.head else None)
print("Tail:", dll.tail.value if dll.tail else None)

dll.pop_first()
print("\nList after fourth pop_first (should make the list empty):")
dll.print_list()
print("Length:", dll.length)
print("Head:", dll.head)
print("Tail:", dll.tail)

# Test pop_first on an empty list
result = dll.pop_first()
print("\nAttempt to pop_first from an empty list:")
print("Result of pop_first:", result)
print("Length:", dll.length)
print("Head:", dll.head)
print("Tail:", dll.tail)
