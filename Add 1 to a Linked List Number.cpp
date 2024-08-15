class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        int cnt9=0, prev=0, len=0;
        Node *temp = head;
        while(temp){
            if(temp->data!=9){
                cnt9=0;
                prev = len;
            }
            else
                cnt9++;
            temp = temp->next;
            len++;
        }
        if(len == cnt9){
            Node *nh = new Node(1);
            nh->next = head;
            while(head){
                head->data=0;
                head=head->next;
            }
            return nh;
        }
        else{
            temp = head;
            while(temp){
                if(!prev) 
                    temp->data++;
                if(prev<0)
                    temp->data=0;
                prev--;
                temp = temp->next;
            }
            return head;
        }
    }
};