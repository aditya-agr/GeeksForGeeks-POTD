class Solution
{
    public:
    int pi;
    //Function to return a tree created from postorder and inoreder traversals.
    Node* dfs(int in[], int post[], int st, int ed){
        if(st>ed)
            return NULL;
        Node* root = new Node(post[pi--]);
        int idx=st;
        for(int i=st; i<=ed; i++){
            if(in[i]==root->data){
                idx=i;
                break;
            }
        }
        root->right = dfs(in, post, idx+1, ed);
        root->left = dfs(in, post, st, idx-1);
    }
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        pi = n-1;
        return dfs(in, post, 0, n-1);
    }
};