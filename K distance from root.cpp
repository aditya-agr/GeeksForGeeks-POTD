class Solution
{
    public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
        // Your code here
        queue<Node*> q;
        q.push(root);
        int l = 0;
        vector<int> res;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* tmp = q.front();
                q.pop();
                if(l==k) res.push_back(tmp->data);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            l++;
            if(k<l) break;
        }
        return res;
    }
};