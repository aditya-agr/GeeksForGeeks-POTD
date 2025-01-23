class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        Node *curr = head;
        while(curr){
            Node *temp = new Node(curr->data);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }
        curr = head;
        while(curr){
            if(curr->random) 
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        Node *newh = head->next, *temp = head->next;
        
        while(curr){
            curr->next = curr->next->next;
            curr = curr->next;
            if(temp->next) temp->next = temp->next->next;
            temp = temp->next;
        }
        return newh;
    }
    
};