
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(x==1){
            if(head->next) head->next->prev = NULL;
            return head->next;
        }
        Node*nhead = head;
        while(x!=1){
            head = head->next;
            x--;
        }
        head->prev->next = head->next;
        if(head->next) head->next->prev = head->prev;
        return nhead;
    }
};