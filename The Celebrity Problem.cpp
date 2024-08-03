class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        vector<int> knows(n), known(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]){
                    knows[i]++;
                    known[j]++;
                }
            }
        }
        for(int i=0; i<n; i++)
            if(knows[i]==0 && known[i]==n-1)
                return i;
        return -1;
    }
};