class Solution {
  public:
    Node* helper(int l, int r, vector<int>&nums){
        if(l>r)
            return NULL;
            
        if(l==r)
           return new Node(nums[l]);
        
        int mid = l + (r-l)/2;
        Node* root = new Node(nums[mid]);
        root->left = helper(l, mid-1, nums);
        root->right = helper(mid+1, r, nums);
        return root;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        int n = nums.size();
        return helper(0, n-1, nums);
    }
};