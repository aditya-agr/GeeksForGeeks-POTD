/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        unordered_map<int, vector<int>> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        int mn=0, mx = 0;
        while(!q.empty()){
            Node* node = q.front().first;
            int idx = q.front().second;
            q.pop();
            mp[idx].push_back(node->data);
            mn = min(mn, idx);
            mx = max(mx, idx);
            if(node->left)
                q.push({node->left, idx-1});
            if(node->right)
                q.push({node->right, idx+1});
        }
        vector<vector<int>> res;
        for(int i=mn; i<=mx; i++)
            res.push_back(mp[i]);
        return res;
    }
};