class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        // Node *curr = head, *nxt = head->next, *prev=NULL;
        // while(curr){
        //     nxt = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nxt;
        // }
        // return prev;

        if(!head->next)
            return head;
        
        Node * curr = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return curr;
    }
};