class Solution {
  public:
    bool isHeap(Node* tree) {
        // code here
        queue<pair<Node*, int>> q;
        int curr = tree->data;
        q.push({tree, curr});
        bool leaf = false;
        while(!q.empty()){
            Node *root = q.front().first;
            int val = q.front().second;
            q.pop();
            if(root->data > val)
                return false;
            if(root->left){
                if(leaf) return false;
                q.push({root->left, val});
            }
            else
                leaf = true;
            if(root->right){
                if(leaf) return false;
                q.push({root->right, val});
            }
            else
                leaf = true;
        }
        return true;
    }
};