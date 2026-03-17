/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    unordered_map<Node*, Node*> parent;
    int solve(Node* root, int prev){
        if(!root)
            return 0;
        int res = 0;
        if(root->left && root->left->data != prev)
            res = max(res, solve(root->left, root->data));
        if(root->right && root->right->data != prev)
            res = max(res, solve(root->right, root->data));
        if(parent.count(root) && parent[root]->data != prev)
            res = max(res, solve(parent[root], root->data));
        return 1+ res;
    }
    int minTime(Node* root, int target) {
        // code here
        Node* tar;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            if(node->data == target)
                tar = node;
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return solve(tar, -1) - 1;
        
    }
};