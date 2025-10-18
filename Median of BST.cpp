
class Solution {
  public:
    void count(Node* root, int &cnt){
        if(!root)
            return ;
        count(root->left, cnt);
        cnt++;
        count(root->right, cnt);
    }
    void solve(Node* root, int &res, int &k){
        if(!root)
            return;
        solve(root->left, res, k);
        k--;
        if(k==0)
            res = root->data;
        solve(root->right, res, k);
        
    }
    int findMedian(Node* root) {
        // Code here
        int cnt = 0;
        count(root, cnt);
        int res = -1;
        int k;
        if(cnt%2)
            k = (cnt+1)/2;
        else
            k = cnt/2;
        solve(root, res, k);
        return res;
    }
};