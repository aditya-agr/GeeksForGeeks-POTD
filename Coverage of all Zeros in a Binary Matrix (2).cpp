class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        // code here
        int res = 0;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    int x=i, y=j;
                    while(x>=0){
                        if(mat[x][y] == 1){
                            res++;
                            break;
                        }
                        x--;
                    }
                    x=i;
                    while(x<n){
                        if(mat[x][y] == 1){
                            res++;
                            break;
                        }
                        x++;
                    }
                    x=i;
                    while(y>=0){
                        if(mat[x][y] == 1){
                            res++;
                            break;
                        }
                        y--;
                    }
                    y=j;
                    while(y<m){
                        if(mat[x][y] == 1){
                            res++;
                            break;
                        }
                        y++;
                    }
                }
            }
        }
        return res;
    }
};
