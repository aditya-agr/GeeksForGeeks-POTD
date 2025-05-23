class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        Node* slow=head, *fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(slow!=fast) return;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        while(slow->next!=fast)
            slow = slow->next;
        slow->next = NULL;
    }
};