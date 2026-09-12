#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

class CircularLinkedList {
    Node* head;
    Node* tail;

    public:
        CircularLinkedList() {
            head = tail = NULL;
        }

        void insertAtHead(int val) {
            Node* newNode = new Node(val);

            if (head == NULL) {
                head = tail = newNode;
                tail->next = head;
            } else {
                newNode->next = head;
                head = newNode;
                tail->next = head;
            }
        }

        void insertAtTail(int val) {
            Node* newNode = new Node(val);

            if (head == NULL) {
                head = tail = newNode;
                tail->next = head;
            } else {
                newNode->next = head;
                tail->next = newNode;
                tail = newNode;
            }
        }

        void deleteAtHead() {
            Node* temp = head;

            if (head == NULL) {
                cout << "List is empty\n";
                return;
            } else if (head == tail) {
                delete head;
                head = tail = NULL;
            } else {
                head = head->next;
                tail->next = head;
                temp->next = NULL;

                delete temp;
            }
        }

        void deleteAtTail() {
            Node* temp = tail;
            Node* prev = head;

            if (head == NULL) {
                cout << "List is empty\n";
                return;
            } else if (head == tail) {
                delete head;
                head = tail = NULL;
            } else {
                while (prev->next != tail) {
                    prev = prev->next;
                }

                tail = prev;
                tail->next = head;
                temp->next = NULL;

                delete temp;
            }

        }

        void printList() {
            Node* temp = head->next;

            cout << head->data << "->";
            while (temp != head) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << head->data;
        }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtHead(5);
    cll.insertAtHead(4);
    cll.insertAtHead(3);
    cll.insertAtHead(2);
    cll.insertAtTail(6);
    cll.insertAtTail(7);
    //cll.deleteAtHead();
    //cll.deleteAtTail();

    cll.printList();

    return 0;
}