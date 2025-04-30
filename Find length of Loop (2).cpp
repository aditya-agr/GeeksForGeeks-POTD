class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node *slow = head;
        Node *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(slow != fast)
            return 0;
        int cnt = 1;
        slow = slow->next;
        while(slow != fast){
            cnt++;
            slow = slow->next;
        }
        return cnt;
    }
};