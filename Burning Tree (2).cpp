class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> parent;
        queue<Node*> q;
        q.push(root);
        Node* fire;
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
            if(node->data == target)
                fire = node;
        }
        queue<pair<Node*, int>> que;
        que.push({fire, -1});
        int tim = 0;
        unordered_set<int> st;
        while(!que.empty()){
            Node *node = que.front().first;
            int t = que.front().second;
            que.pop();
            tim = max(tim, t);
            if(st.count(node->data))
                continue;
            if(node->left)
                que.push({node->left, t+1});
            if(node->right)
                que.push({node->right, t+1});
            if(parent.count(node))
                que.push({parent[node], t+1});
            st.insert(node->data);
        }
        return tim;
    }
};