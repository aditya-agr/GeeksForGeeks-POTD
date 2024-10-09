class Solution {
  public:
    Node* solve(int i, int j, vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        if(i>=n || i<0 || j>=m || j<0)
            return NULL;
        Node *temp = new Node(mat[i][j]);
        temp->right = solve(i, j+1, mat);
        temp->down = solve(i+1, j, mat);
        return temp;
    }
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // code Here
        return solve(0,0, mat);
        
    }
};