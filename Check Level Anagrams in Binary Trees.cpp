/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> solve(Node* root1){
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root1);
        while(!q.empty()){
            int n = q.size();
            vector<int> vec;
            for(int i=0; i<n; i++){
                Node *cur = q.front();
                q.pop();
                vec.push_back(cur->data);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            sort(vec.begin(), vec.end());
            res.push_back(vec);
        }
        return res;
    }
    bool areAnagrams(Node* root1, Node* root2) {
        // code here
        vector<vector<int>> r1 = solve(root1);
        vector<vector<int>> r2 = solve(root2);
        int n = r1.size();
        int m = r2.size();
        if(n != m)
            return false;
        bool res = true;
        for(int i=0; i<n; i++){
            if(r1[i] != r2[i])
                res = false;
        }
        return res;
    }
};
ss