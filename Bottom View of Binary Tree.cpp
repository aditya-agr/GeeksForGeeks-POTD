class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        unordered_map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        int mn=INT_MAX, mx=INT_MIN;
        
        while(!q.empty()){
            Node* node = q.front().first;
            int idx = q.front().second;
            q.pop();
            mp[idx] = node->data;
            mn = min(mn, idx);
            mx = max(mx, idx);
            if(node->left)
                q.push({node->left, idx-1});
            if(node->right)
                q.push({node->right, idx+1});
        }
        vector<int> res;
        for(int i=mn; i<=mx; i++)
            res.push_back(mp[i]);
        return res;
    }
};