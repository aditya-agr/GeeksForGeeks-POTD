class Solution {
  public:
    Node * reverse(Node *head){
        Node *curr=head, *nxt=NULL, *prev=NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        Node *rn1 = reverse(num1);
        Node *rn2 = reverse(num2);
        int carry = 0;
        Node *head = new Node(0);
        Node *newh = head;
        while(rn1 && rn2){
            int curr = rn1->data + rn2->data + carry;
            carry = curr/10;
            curr = curr%10;
            head->next = new Node(curr);
            head = head->next;
            rn1 = rn1->next;
            rn2 = rn2->next;
        }
        while(rn1){
            int curr = rn1->data + carry;
            carry = curr/10;
            curr = curr%10;
            head->next = new Node(curr);
            head = head->next;
            rn1 = rn1->next;
        }
        while(rn2){
            int curr = rn2->data + carry;
            carry = curr/10;
            curr = curr%10;
            head->next = new Node(curr);
            head = head->next;
            rn2 = rn2->next;
        }
        if(carry)
            head->next = new Node(carry);
        
        head = reverse(newh->next);
        while(head->data == 0 && head->next)
            head = head->next;
        return head;
        
    }
};