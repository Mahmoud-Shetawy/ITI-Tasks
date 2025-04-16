#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
} ;

class Stack{
    Node *head;
    int size;
public:
    Stack(){
        head = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void push(int ele){
        Node* n = new Node(ele);
        n->next = head;
        head = n;
        size++;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return 0;
        }
        return head->data;
    }
};

int main(){
    Stack s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);


    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}
