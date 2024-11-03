class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        // Code here
        int len = 0;
        Node *temp = *head;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len%2 == 0;
    }
};