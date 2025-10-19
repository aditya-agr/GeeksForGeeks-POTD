class Solution {
  public:
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        vector<pair<int, int>> diff;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            diff.push_back({abs(target-node->data), node->data});
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        sort(diff.begin(), diff.end());
        vector<int> res;
        for(int i=0; i<k; i++)
            res.push_back(diff[i].second);
        return res;
    }
};