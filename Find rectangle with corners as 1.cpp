class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1){
                    vector<int> idx;
                    for(int k=j+1; k<m; k++){
                        if(mat[i][k] == 1)
                            idx.push_back(k);
                    }
                    if(idx.empty()) continue;
                    for(int l=i+1; l<n; l++){
                        if(mat[l][j] == 1){
                            for(int k : idx)
                                if(mat[l][k] == 1)
                                    return true;
                        }
                    }              
                        
                }
            }
        }
        return false;
    }
};