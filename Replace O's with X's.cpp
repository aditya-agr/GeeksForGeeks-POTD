class Solution {
  public:
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            if(grid[i][0] == 'O'){
                q.push({i, 0});
                grid[i][0] = 'N';
            }
            if(grid[i][m-1] == 'O'){
                q.push({i, m-1});
                grid[i][m-1] = 'N';
            }
        }
        for(int j=0; j<m; j++){
            if(grid[0][j] == 'O'){
                q.push({0, j});
                grid[0][j] = 'N';
            }
            if(grid[n-1][j] == 'O'){
                q.push({n-1, j});
                grid[n-1][j] = 'N';
            }
        }
        vector<vector<int>> dir = {{0,-1}, {0,1}, {1,0}, {-1,0}};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(vector<int> d : dir){
                int i_ = i+d[0];
                int j_ = j+d[1];
                if(i_<0 || i_>=n || j_<0 || j_>=m || grid[i_][j_] == 'N' || grid[i_][j_] == 'X')
                    continue;
                grid[i_][j_] = 'N';
                q.push({i_, j_});
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'O')
                    grid[i][j] = 'X';
                if(grid[i][j] == 'N')
                    grid[i][j] = 'O';
            }
        }
    }
};