class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        Node *slow = head;
        Node *fast = head->next;
        while(slow != fast && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow == fast;
    }
};
