vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node*> q;
    stack<vector<int>> st;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> v;
        for(int i=0; i<n; i++){
            Node* tmp = q.front();
            q.pop();
            v.push_back(tmp->data);
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        st.push(v);
    }
    vector<int> res;
    while(!st.empty()){
        vector<int> vt = st.top();
        st.pop();
        for(int i : vt)
            res.push_back(i);
    }
    return res;
}