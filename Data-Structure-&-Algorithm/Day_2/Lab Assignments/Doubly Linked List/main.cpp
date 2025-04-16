#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};


void insertAtBeginning(Node*& head, int data)
{
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node*& head, int data)
{
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node*& head, int data, int position)
{
    if (position < 1) {
        cout << "Position should be >= 1." << endl;
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;

    for (int i = 1; temp != nullptr && i < position - 1;
         i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position greater than the number of nodes."
             << endl;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}


void deleteAtPosition(Node*& head, int position)
{
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

        Node* temp = head;
    if (position == 1) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }


    for (int i = 1; temp != nullptr && i < position; i++) {
        temp = temp->next;
    }


    if (temp == nullptr) {
        cout << "Position is greater than the number of "<< endl;
        return;
    }


    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    delete temp;
}


void printList(Node* head)
{
    Node* temp = head;
    cout << "Print-----> List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main()
{
    Node* head = nullptr;


    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtBeginning(head, 5);
    insertAtPosition(head, 15, 2);

    cout << "After Insertions:" << endl;
    printList(head);

    deleteAtPosition(head, 3);
    cout << "After Delete:" << endl;
    printList(head);


    return 0;
}