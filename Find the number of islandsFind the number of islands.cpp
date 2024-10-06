class Solution {
  public:
    // Function to find the number of islands.
    int dir[8][2] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
    void dfs(int i, int j, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || i<0 || j>=m || j<0 || grid[i][j]=='0')
            return;
        grid[i][j] = '0';
        for(int x=0; x<8; x++)
            dfs(i+dir[x][0], j+dir[x][1], grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int cnt=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};