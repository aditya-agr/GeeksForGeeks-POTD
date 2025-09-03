/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(!head || !head->next)
            return head;
        Node* prev = NULL;
        Node* curr = head;
        Node* nxt = head->next;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            curr->prev = nxt;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};