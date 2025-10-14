class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        int sum = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            if(node->data >= l && node->data <= r)
                sum += node->data;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return sum;
    }
};