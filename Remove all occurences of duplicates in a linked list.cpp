class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        Node *temp = new Node(0);
        temp->next = head;
        Node *prev=temp;
        while(head){
            while(head->next && prev->next->data == head->next->data)
                head = head->next;
            if(prev->next==head)
                prev = head;
            else    
                prev->next = head->next;
            head = head->next;
        }
        return temp->next;
    }
};