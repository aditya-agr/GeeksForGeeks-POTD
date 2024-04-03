class Solution
{
    public:
    void LCA(Node *root, int x, int y, vector<int>&path){
        if(!root) return;
        path.push_back(root->data);
        if(root->data < x && root->data < y)
            LCA(root->right, x, y, path);
        else if(root->data > x && root->data > y)
            LCA(root->left, x, y, path);
        else
            return;
    }
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        vector<int>path;
        LCA(root, x, y, path);
        int n=path.size();
        if(n<k) return -1;
        return path[n-k];
    }
};