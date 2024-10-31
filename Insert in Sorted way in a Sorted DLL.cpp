class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        Node* node = new Node();
        node->data = x;
        if(head->data > x){
            head->prev = node;
            node->next = head;
            return node;
        }
        Node * temp = head;
        while(temp->next && temp->next->data < x)
            temp = temp->next;
        node->next = temp->next;
        if(temp->next) 
            temp->next->prev = node;
        temp->next = node;
        node->prev = temp;
        return head;
    }
};
