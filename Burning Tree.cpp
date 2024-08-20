class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(root);
        Node* trgt;
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            if(node->data == target)
                trgt = node;
            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        unordered_set<int> st;
        queue<pair<Node*, int>> que;
        que.push({trgt, -1});
        int ans=0;
        while(!que.empty()){
            Node *node = que.front().first;
            int it = que.front().second;
            que.pop();
            ans = max(ans, it);
            if(st.count(node->data))
                continue;
            if(node->left)
                que.push({node->left, it+1});
            if(node->right)
                que.push({node->right, it+1});
            if(mp.count(node))
                que.push({mp[node], it+1});
                
            st.insert(node->data);
        }
        return ans;
    }
};