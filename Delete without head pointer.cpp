class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node)
    {
       // Your code here
       Node * curr = del_node, *prev=NULL;
       int flag=0;
       while(curr->next){
           if(curr == del_node) flag=1;
           curr->data = (flag==1) ? curr->next->data : NULL;
           prev=curr;
           curr = curr->next;
       }
       prev->next = NULL;
    }

};