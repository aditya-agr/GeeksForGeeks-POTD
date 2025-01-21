class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(!head) return NULL;
        if(k==1) return head;
        Node *curr=head, *nxt=head->next, *prev=NULL;
        int cnt = 0;
        while(curr && cnt<k){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }
        if(nxt) 
            head->next = reverseKGroup(nxt, k);
        return prev;
    }
};