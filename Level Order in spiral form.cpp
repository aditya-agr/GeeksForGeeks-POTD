class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        int flag = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int> cur;
            for(int i=0; i<n; i++){
                Node *node = q.front();
                q.pop();
                cur.push_back(node->data);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(flag) 
                reverse(cur.begin(), cur.end());
            flag ^= 1;
            for(int i=0; i<n; i++)
                res.push_back(cur[i]);
        }
        return res;
    }
};