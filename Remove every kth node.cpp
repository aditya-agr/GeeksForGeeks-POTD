
class Solution {
    public:
    Node* deleteK(Node *head,int K){
        //Your code here
        if(K==1) return NULL;
        Node*curr = head, *prev = NULL, *had = head;
        int k=1;
        while (curr){
            if(k==K){
                prev->next = curr->next;
                curr = curr->next;
                k = 1;
            }
            else{
                prev = curr;
                curr = curr->next;
                k++;
            }
        }
        return had;
    }
};