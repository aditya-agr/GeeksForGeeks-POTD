class Solution {
  public:
    int getCount(Node *root, int k) {
        // code here
        queue<Node*> q;
        q.push(root);
        int lvl = 1;
        int res = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* node = q.front();
                q.pop();
                if(!node->left && !node->right){
                    if(k >= lvl){
                        res++;
                        k -= lvl;
                    }
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            lvl++;
        }
        return res;
    }
};