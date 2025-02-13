class Solution {
  public:
    void inorder(Node* root, vector<int> &arr){
        if(!root)
            return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<int> arr;
        inorder(root, arr);
        int i=0, j=arr.size()-1;
        while(i<j){
            int sum = arr[i] + arr[j];
            if(sum < target)
                i++;
            else if(sum > target)
                j--;
            else
                return true;
        }
        return false;
    }
};