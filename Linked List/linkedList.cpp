#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

class Linkedlist {
    Node *head;
    Node *tail;

    public:
        Linkedlist() {
            head = tail = NULL;
        }
        
        void push_front(int val) {
            Node *newNode = new Node(val);
            if (head == NULL) {
                head = tail = newNode;
                return;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }

        void push_back(int val) {
            Node *newNode = new Node(val);
            if (head == NULL) {
                head = tail = newNode;
                return;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void pop_front() {
            if (head == NULL) {
                cout << "Linked list is empty\n";
                return;
            }

            Node *temp = head;
            head = head->next;
            temp->next = NULL;

            delete temp;
        }

        void pop_back() {
            if (head == NULL) {
                cout << "Linked list is empty\n";
                return;
            }

            Node *temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }

        void insert(int val, int pos) {
            if (pos < 0) {
                cout << "Invalid position\n";
                return;
            }

            if (pos == 0) {
                push_front(val);
                return;
            }

            Node *temp = head;
            for (int i = 0; i < pos-1; i++) {
                if (temp == NULL) {
                    cout << "Invalid position\n";
                    return;
                }
                temp = temp->next;
            }

            Node *newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void printList() {
            Node *temp = head;
            while (temp != NULL) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }

        int search(int key) {
            Node *temp = head;
            int idx = 0;

            while (temp != NULL) {
                if (temp->data == key) {
                    return idx;
                }
                temp = temp->next;
                idx++;
            }

            return -1;
        }

        void reverseList() {
            Node *prev = NULL;
            Node *curr = head;
            Node *next = NULL;

            while (curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;
        }

        Node* middleNode() {
            Node *slow = head;
            Node *fast = head;

            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        }

        Node* detectCycle() {
            Node *slow = head;
            Node *fast = head;
            bool isCycle = false;

            while (fast != NULL && fast->next != NULL) {    //detect cycle
                slow = slow->next;
                fast = fast->next->next;
                
                if (slow == fast) {
                    isCycle = true;
                    break;
                }
            }

            if (!isCycle) {
                return NULL;
            }

            slow = head;
            Node *prev = NULL;

            while (slow != fast) {
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }

            prev->next = NULL;  //remove cycle
            return slow;        //return cycle starting point
        }
};

int main() {
    Linkedlist ll;

    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(9);
    ll.push_back(10);
    ll.push_front(1);
    //ll.pop_front();
    //ll.pop_back();
    ll.insert(11, 2);
    //ll.reverseList();
    
    ll.printList();
    //cout << ll.search(11) << endl;
    cout << ll.middleNode()->data << endl;
    
    return 0;
}