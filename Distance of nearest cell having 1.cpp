class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    q.push({i, j});
                    res[i][j] = 0;
                    vis[i][j] = true;
                } 
            }
        }
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(vector<int> d : dir){
                int i_ = i+d[0];
                int j_ = j+d[1];
                if(i_<0 || i_>=n || j_<0 || j_>=m || vis[i_][j_])
                    continue;
                res[i_][j_] = res[i][j]+1;
                vis[i_][j_] = true;
                q.push({i_, j_});
            }
        }
        return res;
    }
};