class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        if(!head || !head->next)
            return head;
        int len = 1;
        Node *temp = head;
        while(temp->next){
            temp = temp->next;
            len++;
        }
        k %= len;
        temp->next = head;
        while(k--)
            temp = temp->next;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};