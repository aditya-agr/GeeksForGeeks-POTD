class Solution {
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        queue<pair<Node*, long long>> q;
        q.push({root, root->data});
        int res = 0;
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            for(int i=0; i<n; i++){
                Node *node = q.front().first;
                int cur = q.front().second;
                sum = max(cur, sum);
                q.pop();
                if(node->left)
                    q.push({node->left, cur+node->left->data});
                if(node->right)
                    q.push({node->right, cur+node->right->data});
            }
            res = sum;
        }
        return res;
    }
};