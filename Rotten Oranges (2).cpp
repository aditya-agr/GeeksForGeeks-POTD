class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 2)
                    q.push({i, j});
            }
        }
        int res = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(vector<int> &d : dir){
                    int x_ = x+d[0];
                    int y_ = y+d[1];
                    if(x_<0 || x_>=n || y_<0 || y_>=m || mat[x_][y_] != 1)
                        continue;
                    mat[x_][y_] = 2;
                    q.push({x_, y_});
                }
            }
            res++;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1)
                    return -1;
            }
        }
        return res == 0 ? 0 : res-1;
    }
};