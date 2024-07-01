/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    // Your code here
    queue<TreeNode*> q;
    root = new TreeNode(head->data);
    head = head->next;
    q.push(root);
    while(head){
        TreeNode *curr = q.front();
        q.pop();
        curr->left = new TreeNode(head->data);
        head = head->next;
        q.push(curr->left);
        if(!head)
            break;
        curr->right = new TreeNode(head->data);
        head = head->next;
        q.push(curr->right);
    }
}
