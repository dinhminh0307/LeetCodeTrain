#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList(): head(NULL) {}

    void insertAtBeginning(int val) {
        Node* new_node = new Node();
        new_node->data = val;
        new_node->next = head;
        head = new_node;
    }

    void insertAtEnd(int val) {
        Node* new_node = new Node();
        new_node->data = val;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = new_node;
    }

    void insertAtPosition(int val, int pos) {
        Node* new_node = new Node();
        new_node->data = val;

        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp) {
            delete new_node;
            return;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) {
            return;
        }

        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void deleteAtPosition(int pos) {
        if (!head || pos < 1) {
            return;
        }

        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            return;
        }

        Node* node_to_delete = temp->next;
        temp->next = temp->next->next;
        delete node_to_delete;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(5);
    list.insertAtBeginning(10);
    list.insertAtEnd(15);
    list.insertAtPosition(20, 2);
    list.printList(); // Expected output: 10 -> 20 -> 5 -> 15 -> NULL
    
    list.deleteAtPosition(2);
    list.printList(); // Expected output: 10 -> 5 -> 15 -> NULL

    return 0;
}
