#include <iostream>
#include <cstdlib>   // for malloc, free
using namespace std;
// https://chat.deepseek.com/share/p4ym6db9qnl1wp63jl
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

    // Helper: create a node using malloc (constructor won't run)
    Node* createNode(int value) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        return newNode;
    }

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // ---------------- PUSH FRONT ----------------
    void pushFront(int value) {
        Node* newNode = createNode(value);

        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // ---------------- PUSH BACK ----------------
    void pushBack(int value) {
        Node* newNode = createNode(value);

        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // ---------------- POP FRONT ----------------
    int popFront() {
        if (head == nullptr) {
            cout << "List is empty! Cannot popFront." << endl;
            return -1;
        }

        Node* temp = head;
        int value = temp->data;

        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;   // list became empty

        free(temp);
        return value;
    }

    // ---------------- POP BACK ----------------
    int popBack() {
        if (tail == nullptr) {
            cout << "List is empty! Cannot popBack." << endl;
            return -1;
        }

        Node* temp = tail;
        int value = temp->data;

        tail = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;   // list became empty

        free(temp);
        return value;
    }

    // ---------------- INSERT AT POSITION ----------------
    // Position starts from 1. Position = 1 means insert at front.
    // Position = size+1 means insert at back.
    void insertAt(int position, int value) {
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        // Insert at front
        if (position == 1) {
            pushFront(value);
            return;
        }

        Node* temp = head;

        // Move to node just before the target position
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position! (beyond list length + 1)" << endl;
            return;
        }

        // Insert at back
        if (temp == tail) {
            pushBack(value);
            return;
        }

        // Insert in the middle
        Node* newNode = createNode(value);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // ---------------- DELETE AT POSITION ----------------
    void deleteAt(int position) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        // Delete first node
        if (position == 1) {
            Node* temp = head;
            head = head->next;

            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;

            free(temp);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position!" << endl;
            return;
        }

        // Delete last node
        if (temp == tail) {
            tail = temp->prev;
            tail->next = nullptr;
            free(temp);
            return;
        }

        // Delete middle node
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }

    // ---------------- DISPLAY FORWARD ----------------
    void displayForward() {
        Node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // ---------------- DISPLAY BACKWARD ----------------
    void displayBackward() {
        Node* temp = tail;
        cout << "Backward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Push Front
    list.pushFront(20);
    list.pushFront(10);

    // Push Back
    list.pushBack(30);
    list.pushBack(40);

    cout << "Initial list:" << endl;
    list.displayForward();     // 10 20 30 40
    list.displayBackward();    // 40 30 20 10

    // Insert at position 3 (between 20 and 30)
    list.insertAt(3, 25);
    cout << "\nAfter insertAt(3, 25):" << endl;
    list.displayForward();     // 10 20 25 30 40
    list.displayBackward();

    // Pop front
    cout << "\npopFront() returned: " << list.popFront() << endl;
    list.displayForward();     // 20 25 30 40

    // Pop back
    cout << "popBack() returned: " << list.popBack() << endl;
    list.displayForward();     // 20 25 30

    // Delete position 2
    list.deleteAt(2);
    cout << "\nAfter deleting position 2:" << endl;
    list.displayForward();     // 20 30
    list.displayBackward();

    return 0;
}
