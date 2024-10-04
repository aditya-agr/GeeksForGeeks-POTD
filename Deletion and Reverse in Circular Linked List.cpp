class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
        Node* prev=head, *curr=head->next, *nxt;
        while(curr!=head){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = prev;
        return prev;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // code here
        Node* prev=head, *temp=head->next;
        if(head->data == key){
            while(temp!=head){
                prev = temp;
                temp = temp->next;
            }
        }
        else{
            while(temp != head && temp->data != key){
                prev = temp;
                temp = temp->next;
            }
        }
        if(head->data == key || head != temp)
            prev->next = temp->next;
        return (head->data == key) ? prev->next : head;
        
    }
};