#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
    int size;

public:
    Queue(){
        head = NULL;
        tail = NULL;
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
        if(head==NULL){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
        size++;
    }
    int front(){
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
    void pop(){
        if(isEmpty()){
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
};
int main(){
    Queue q;
    cout<<q.isEmpty()<<endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);

    cout<<"Front is  ===> "<<q.front()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<"Front is after Pop  ===> "<<q.front()<<endl;
    cout<<"size of Queue ===> "<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
    q.push(60);
    q.push(70);

    q.pop();
    q.pop();
    cout<<"Front is  ===> "<<q.front()<<endl;
    cout<<"size of Queue ===> "<<q.getSize()<<endl;

    while(!q.isEmpty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    cout<<"size of Queue ===> "<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}
