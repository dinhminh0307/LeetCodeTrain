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
    
    def get(self, index)-> Node:
        if index < 0 :
            return None
        if self.head == None and self.tail == None:
            return None
        if self.length == 1:
            return self.head
        tmp = self.head

        for i in range(index):
            tmp = tmp.next
            if tmp == None:
                return None
        return tmp
    
    def set(self, index, value) -> bool:
        temp = self.get(index)
        if temp:
            temp.value = value
        else:
            return False
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
# Initialize a new list
# dll = DoublyLinkedList(10)
# dll.append(20)
# dll.append(30)
# dll.append(40)

# print("Initial list:")
# dll.print_list()
# print("Length:", dll.length)
# print("Head:", dll.head.value if dll.head else None)
# print("Tail:", dll.tail.value if dll.tail else None)

# # Test get method with various indices
# print("\nTesting get method:")

# # Get element at index 0 (first element)
# node = dll.get(0)
# print("Element at index 0:", node.value if node else None)  # Expected: 10

# # Get element at index 1
# node = dll.get(1)
# print("Element at index 1:", node.value if node else None)  # Expected: 20

# # Get element at index 2
# node = dll.get(2)
# print("Element at index 2:", node.value if node else None)  # Expected: 30

# # Get element at index 3 (last element)
# node = dll.get(3)
# print("Element at index 3:", node.value if node else None)  # Expected: 40

# # Get element at index out of bounds (e.g., 4)
# node = dll.get(4)
# print("Element at index 4 (out of bounds):", node.value if node else None)  # Expected: None

# # Get element at index -1 (negative index)
# node = dll.get(-1)
# print("Element at index -1 (negative index):", node.value if node else None)  # Expected: None

# Initialize a new list for testing
dll = DoublyLinkedList(10)
dll.append(20)
dll.append(30)
dll.append(40)

print("Initial list:")
dll.print_list()
print("Length:", dll.length)
print("Head:", dll.head.value if dll.head else None)
print("Tail:", dll.tail.value if dll.tail else None)

# Test set method with various indices
print("\nTesting set method:")

# Set element at index 0 (first element)
result = dll.set(0, 15)
print("Set index 0 to 15:", "Success" if result else "Failed")
dll.print_list()  # Expected list: 15 -> 20 -> 30 -> 40

# Set element at index 2
result = dll.set(2, 35)
print("Set index 2 to 35:", "Success" if result else "Failed")
dll.print_list()  # Expected list: 15 -> 20 -> 35 -> 40

# Set element at index 3 (last element)
result = dll.set(3, 45)
print("Set index 3 to 45:", "Success" if result else "Failed")
dll.print_list()  # Expected list: 15 -> 20 -> 35 -> 45

# Try to set element at an out-of-bounds index (e.g., 4)
result = dll.set(4, 50)
print("Set index 4 to 50 (out of bounds):", "Success" if result else "Failed")
dll.print_list()  # Expected list (unchanged): 15 -> 20 -> 35 -> 45

# Try to set element at a negative index (e.g., -1)
result = dll.set(-1, 5)
print("Set index -1 to 5 (negative index):", "Success" if result else "Failed")
dll.print_list()  # Expected list (unchanged): 15 -> 20 -> 35 -> 45
