#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node (int data){
        this->data = data;
        this->next = NULL;
    }
};
Node* insertAtHead(Node* head, int data){
    Node* newNode = new Node(data);
    if (head == NULL){
        return newNode;
    }
    newNode->next = head;
    head = newNode;

    return head;
}
Node* insertAtEnd(Node* head, int data){
    if (head == NULL){
        return insertAtHead(head, data);
    }
    Node* temp = head;
    Node* newNode = new Node(data);
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}
int length(Node* head){
    int len = 0;
    while (head != NULL){
        head = head->next;
        len++;
    }

    return len;
}
Node* insertAtPosition(Node* head, int pos, int data){
    if (pos == 1 || pos == 0){
        return insertAtEnd(head, data);
    }
    int len = length(head);
    if (pos == len) return insertAtEnd(head, data);
    if (pos > len || pos < 0) return head;

    int i = 0;
    Node* temp = head;
    Node* newNode = new Node(data);
    while (i < pos - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }
    
    Node* next = temp->next;
    temp->next = newNode;
    newNode->next = next;

    return head;
}
void print(Node* head){
    if (head == NULL){
        cout << "No Node exist" << endl;
        return ;
    }

    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);
    Node* node10 = new Node(10);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;

    cout << "Printing Initial List " << endl;
    print(head);

    cout << "Insert At Head = 50" << endl;
    head = insertAtHead(head, 50);
    cout << "Printing the updated List " << endl;
    print(head);

    cout << "Insert At End = 50" << endl;
    head = insertAtEnd(head, 50);
    cout << "Printing the updated List " << endl;
    print(head);

    cout << "Insert At Pos 2" << endl;
    head = insertAtPosition(head, 2, 50);
    cout << "Printing the updated List " << endl;
    print(head);

    return 0;
}