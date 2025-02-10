class Solution {
  public:
    int count = 0, curr = 0;
    unordered_map<int, int> mp;
    int sumK(Node *root, int k) {
        // code here
        if(!root)
            return 0;
        curr += root->data;
        if(curr == k) 
            count++;
        count += mp[curr-k];
        mp[curr]++;
        sumK(root->left, k);
        sumK(root->right, k);
        mp[curr]--;
        curr -= root->data;
        return count;
    }
};