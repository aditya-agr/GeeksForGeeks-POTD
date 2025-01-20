class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node * res = new Node(0);
        Node *newHead = res;
        while(head1 && head2){
            if(head1->data < head2->data){
                res->next = head1;
                head1 = head1->next;
            }
            else{
                res->next = head2;
                head2 = head2->next;
            }
            res = res->next;
        }
        while(head1){
            res->next = head1;
            head1 = head1->next;
            res = res->next;
        }
        while(head2){
            res->next = head2;
            head2 = head2->next;
            res = res->next;
        }
        return newHead->next;
    }
};