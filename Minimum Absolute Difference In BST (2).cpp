class Solution {
  public:
    int absDiff(Node *root) {
        // code here
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            res.push_back(cur->data);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        int n = res.size();
        int ans = INT_MAX;
        sort(res.begin(), res.end());
        for(int i=1; i<n; i++)
            ans = min(ans, res[i]-res[i-1]);
        return ans;
    }
};