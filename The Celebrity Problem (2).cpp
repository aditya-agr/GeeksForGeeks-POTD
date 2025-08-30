class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        vector<int> res;
        int n = mat.size();
        for(int i=0; i<n; i++){
            int flag = 1;
            for(int j=0; j<n; j++){
                if(mat[j][i] == 0)
                    flag = 0;
            }
            if(flag)
                res.push_back(i);
        }
        for(int x : res){
            int flag = 1;
            for(int j=0; j<n; j++){
                if(x!=j && mat[x][j] == 1)
                    flag = 0;
            }
            if(flag)
                return x;
        }
        return -1;
    }
};