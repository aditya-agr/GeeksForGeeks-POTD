class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
        queue<Node*> q;
        int h = 0;
        q.push(node);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node *node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            h++;
        }
        return h-1;
    }
};