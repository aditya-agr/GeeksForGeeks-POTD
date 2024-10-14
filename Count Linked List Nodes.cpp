class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        // Code here
        int len=0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
};