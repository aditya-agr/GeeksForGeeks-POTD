class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        int n1=0, n2=0;
        Node* temp = head1;
        while(temp){
            n1++;
            temp = temp->next;
        }
        temp = head2;
        while(temp){
            n2++;
            temp = temp->next;
        }
        while(n1<n2){
            head2 = head2->next;
            n2--;
        }
        while(n1>n2){
            head1 = head1->next;
            n1--;
        }
        while(head1 && head2){
            if(head1 == head2)
                return head1->data;
            head1 = head1->next;
            head2 = head2->next;
        }
        return -1;
    }
};