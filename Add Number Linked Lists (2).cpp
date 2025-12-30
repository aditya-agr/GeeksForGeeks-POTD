/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* reverse(Node *head){
        if(!head)
            return NULL;
        Node* curr=head, *nxt=head->next, *prev=NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
  
  
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        while(head1 && head1->data == 0)
            head1 = head1->next;
        while(head2 && head2->data == 0)
            head2 = head2->next;
        
        if(!head1)
            return head2;
        if(!head2)
            return head1;
            
        Node* h1 = reverse(head1);
        Node* h2 = reverse(head2);
        Node* res = new Node(0);
        Node* temp = res;
        int rem = 0;
        while(h1 || h2){
            int curr = rem;
            if(h1){
                curr += h1->data;
                h1 = h1->next;
            }
            if(h2){
                curr += h2->data;
                h2 = h2->next;
            } 
            rem = curr/10;
            Node* node = new Node(curr%10);
            temp->next = node;
            temp = temp->next;
        }
        if(rem){
            Node* node = new Node(rem);
            temp->next = node;
        }
        return reverse(res->next);   
    }
};