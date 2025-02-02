class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){
            int n = q.size();
            vector<int> curr;
            while(n--){
                Node *ft = q.front();
                curr.push_back(ft->data);
                q.pop();
                if(ft->left)
                    q.push(ft->left);
                if(ft->right)
                    q.push(ft->right);
            }
            res.push_back(curr);
        }
        return res;
    }
};