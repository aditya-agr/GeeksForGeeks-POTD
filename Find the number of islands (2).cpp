class Solution {
  public:
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,-1}, {-1,-1}, {1,1}, {-1,1}};
    void dfs(vector<vector<char>> &grid, int i, int j){
        grid[i][j] = '#';
        int n = grid.size();
        int m = grid[0].size();
        for(vector<int> dir : directions){
            int i_ = i+dir[0];
            int j_ = j+dir[1];
            if(i_>=0 && i_<n && j_>=0 && j_<m && grid[i_][j_]=='L')
                dfs(grid, i_, j_);
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'L'){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
};