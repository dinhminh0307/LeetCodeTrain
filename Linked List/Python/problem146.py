class Node:
    def __init__(self, key, value) -> None:
        self.key = key  # Add key to allow for easier deletion from dictionary
        self.value = value
        self.next = None
        self.prev = None

class LRUCache:

    def __init__(self, capacity: int) -> None:
        self.head = None  # Most recently used
        self.tail = None  # Least recently used
        self.m = {}
        self.capacity = capacity

    def get(self, key: int) -> int:
        if self.head is None:
            return -1  # Cache is empty
        if key not in self.m:
            return -1  # Key not found
        
        node = self.m[key]
        
        # Move the accessed node to the head if it's not already there
        if node != self.head:
            # Detach the node from its current position
            if node.prev:
                node.prev.next = node.next
            if node.next:
                node.next.prev = node.prev
            if node == self.tail:
                self.tail = node.prev  # Update tail if node was the tail
            
            # Move node to the head
            node.prev = None
            node.next = self.head
            if self.head:
                self.head.prev = node
            self.head = node

            if self.tail is None:  # If only one node, head and tail are the same
                self.tail = node
        
        return node.value

    def put(self, key: int, value: int) -> None:
        if key in self.m:
            # If key exists, update value and move to head
            existing_node = self.m[key]
            existing_node.value = value
            self.get(key)  # Move to head by calling get
            return

        # If cache is full, remove the least recently used node (tail)
        if len(self.m) >= self.capacity:
            if self.tail:
                # Remove tail node from dictionary and update tail
                del self.m[self.tail.key]
                if self.tail.prev:
                    self.tail = self.tail.prev
                    self.tail.next = None
                else:
                    # If only one element existed
                    self.head = None
                    self.tail = None

        # Add the new node to the head
        new_node = Node(key, value)
        new_node.next = self.head
        if self.head:
            self.head.prev = new_node
        self.head = new_node

        if self.tail is None:
            # If list was empty, new node is also the tail
            self.tail = new_node

        # Update dictionary with new node
        self.m[key] = new_node
