class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(mat[i][j] == 2)
                    q.push({i, j});
        
        int t = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(vector<int> dir : directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if(i_>=0 && i_<n && j_>=0 && j_<m && mat[i_][j_]==1){
                        mat[i_][j_] = 2;
                        q.push({i_, j_});
                    }
                }
            } 
            t++;
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(mat[i][j] == 1)
                    return -1;
        return t==0 ? 0 : t-1;
    }
};