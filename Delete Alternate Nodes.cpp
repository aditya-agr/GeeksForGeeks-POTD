class Solution {
  public:
    void deleteAlt(struct Node *head) {
        // Code here
         if(head==NULL){
            return;
        }
        struct Node *temp=head;
        while(temp!=NULL&&temp->next!=NULL){
            temp->next=temp->next->next;
            temp=temp->next;
        }
    }
};