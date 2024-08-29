class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        if(!head || !head->next)
            return 0;
        Node *slow=head, *fast=head->next;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                break;
        }
        if(slow!=fast)
            return 0;
        int cnt=1;
        slow = slow->next;
        while(slow!=fast){
            cnt++;
            slow = slow->next;
        }
        return cnt;
    }
};