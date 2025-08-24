/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Compare {
    public:
        bool operator()(ListNode* &a, ListNode* &b){
            return a->val > b->val;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int i = 0; i < n; i++){
            if (lists[i]) pq.push(lists[i]);
        }

        while (!pq.empty()){
            auto top = pq.top();pq.pop();
            curr->next = top;
            curr = curr->next;
            if (top->next){
                pq.push(top->next);
            }
        }


        return dummy->next;
    }
};








