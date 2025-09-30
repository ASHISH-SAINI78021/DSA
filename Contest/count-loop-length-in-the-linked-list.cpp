// Node is defined as
// struct Node{
//   int data=0;
//   Node* next;
//   Node(){
//         this->data = 0;
//         this->next = nullptr;
//   }
//   Node(int data){
//       this->data = data;
//       this->next = nullptr;
//   }
// };
int solve(Node* head){
   if (head == NULL) return -1;
   
   Node* slow = head;
   Node* fast = head;
   
   while (fast != NULL){
       slow = slow->next;
       fast = fast->next;
       if (fast) fast = fast->next;
       if (slow == fast){
           slow = head;
           while (slow != fast){
               slow = slow->next;
               fast = fast->next;
           }
           Node* end = slow;
           slow = slow->next;
           int count = 1;
           while (slow != end){
               slow = slow->next;
               count++;
           }
           
           return count;
       }
   }
   
   return -1;
}