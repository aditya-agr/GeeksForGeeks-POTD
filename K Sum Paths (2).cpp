/*
class Node {
  public:
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
    unordered_map<int, int> mp;
    void solve(Node* root, int &cur, int &cnt, int &k){
        if(!root)
            return;
        cur += root->data;
        cnt += mp[cur-k];
        mp[cur]++;
        solve(root->left, cur, cnt, k);
        solve(root->right, cur, cnt, k);
        mp[cur]--;
        cur -= root->data;
    }
    int countAllPaths(Node *root, int k) {
        // code here
        int cnt = 0, cur = 0;
        mp[0]= 1;
        solve(root, cur, cnt, k);
        return cnt;
    }
};