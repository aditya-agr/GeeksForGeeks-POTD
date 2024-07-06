struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* nxt = NULL;
    void populateNext(Node *root) {
        // code here
        if(!root) return;
        populateNext(root->right);
        root->next = nxt;
        nxt = root;
        populateNext(root->left);
    }
};