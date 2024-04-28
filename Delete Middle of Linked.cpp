class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        // Your Code Here
        if(head->next==NULL)return NULL;
        Node *slow=head,*fast=head,*temp=NULL;
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=slow->next;
        return head;
    }
};