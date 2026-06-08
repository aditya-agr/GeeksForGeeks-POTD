class Solution {
  public:
    Node *reverse(Node* root){
        Node* prev = NULL;
        Node* curr = root;
        Node* nxt = curr->next;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    Node *compute(Node *head) {
        // code here
        Node *root = reverse(head);
        Node *prev = root;
        Node *curr = root->next;
        while(curr){
            if(curr->data < prev->data)
                prev->next = curr->next;
            else
                prev = curr;
            curr = curr->next;
        }
        return reverse(root);
    }
};