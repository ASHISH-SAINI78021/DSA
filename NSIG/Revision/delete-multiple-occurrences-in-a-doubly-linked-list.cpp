#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

Node* deleteAllOccurencesOfAKey(Node* head, int key){
    if (head == NULL) return head;
    
    Node* temp = head;
    while (temp != NULL){
        if (temp->data == key){
            Node* del = temp;

            if (temp->prev == NULL){
                // deleting head
                head = temp->next;
                if (head) head->prev = NULL;
                temp = head;
            }
            else {
                // middle or tail
                temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                temp = temp->next;
            }

            delete del;
        }
        else {
            temp = temp->next;
        }
    }

    return head;
}

int main(){
    return 0;
}
