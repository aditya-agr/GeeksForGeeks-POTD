/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        unordered_map<int, int> mp;
        int mn=0, mx=0;
        mp[0] = root->data;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            Node* node = q.front().first;
            int idx = q.front().second;
            q.pop();
            if(node->left){
                if(!mp.count(idx-1)){
                    mp[idx-1] = node->left->data;
                    mn = min(mn, idx-1);
                }
                q.push({node->left, idx-1});
            }
            if(node->right){
                if(!mp.count(idx+1)){
                    mp[idx+1] = node->right->data;
                    mx = max(mx, idx+1);
                }
                q.push({node->right, idx+1});
            }
        }
        vector<int> res;
        for(int i=mn; i<=mx; i++)
            res.push_back(mp[i]);
        return res;
    }
};