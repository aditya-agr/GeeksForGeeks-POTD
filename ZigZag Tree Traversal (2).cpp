/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        queue<Node*> q;
        q.push(root);
        vector<int> res;
        bool flag = true;
        
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            
            for(int i=0; i<n; i++){
                Node* ft = q.front();
                q.pop();
                if(ft->left)
                    q.push(ft->left);
                if(ft->right)
                    q.push(ft->right);
                temp.push_back(ft->data);
            }
            if(!flag)
                reverse(temp.begin(), temp.end());
            flag = !flag;
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};