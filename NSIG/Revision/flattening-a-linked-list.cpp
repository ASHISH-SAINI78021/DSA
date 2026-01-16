/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node* part1, Node* part2){
        Node* dummy = new Node(0);
        Node* curr = dummy;
        while (part1 && part2){
            if (part1->data > part2->data){
                curr->bottom = part2;
                part2 = part2->bottom;
                curr = curr->bottom;
            }
            else {
                curr->bottom = part1;
                part1 = part1->bottom;
                curr = curr->bottom;
            }
        }
        
        while (part1){
            curr->bottom = part1;
            part1 = part1->bottom;
            curr = curr->bottom;
        }
        
        while (part2){
            curr->bottom = part2;
            part2 = part2->bottom;
            curr = curr->bottom;
        }
        
        return dummy->bottom;
    }
    Node *flatten(Node *root) {
        if (root == NULL) return root;
        Node* dummy = NULL;
        Node* temp = root;
        while (temp != NULL){
            dummy = merge(dummy, temp);
            temp = temp->next;
        }
        
        return dummy;
    }
};