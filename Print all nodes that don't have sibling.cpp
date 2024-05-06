vector<int> noSibling(Node* root)
{
    // code here
    vector<int> res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node * tmp = q.front();
        q.pop();
        if(tmp->left && !tmp->right) res.push_back(tmp->left->data);
        if(!tmp->left && tmp->right) res.push_back(tmp->right->data);
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
    sort(res.begin(), res.end());
    return res.empty() ? vector<int>(1,-1) : res;
}