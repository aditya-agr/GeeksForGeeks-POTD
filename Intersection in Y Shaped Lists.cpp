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
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int l1 = 0;
        Node* temp = head1;
        while(temp){
            l1++;
            temp = temp->next;
        }
        int l2 = 0;
        temp = head2;
        while(temp){
            l2++;
            temp = temp->next;
        }
        if(l2 > l1){
            while(l2 != l1){
                l2--;
                head2 = head2->next;
            }
        }
        else{
            while(l2 != l1){
                l1--;
                head1 = head1->next;
            }
            
        }
        while(head1 != head2){
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1;
    }
};