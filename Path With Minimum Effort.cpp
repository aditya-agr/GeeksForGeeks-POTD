class Solution {
  public:
    int MinimumEffort(int row, int col, vector<vector<int>> &heights) {
        // code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        
        vector<vector<int>> dp(row, vector<int>(col, 1e9));
        dp[0][0] = 0;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int eff = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if (x==row-1 && y==col-1) return eff;
            
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<row && nx>=0 && ny<col && ny>=0){
                    int neff = max(eff, abs(heights[x][y]-heights[nx][ny]));
                    if(neff<dp[nx][ny]){
                        dp[nx][ny] = neff;
                        pq.push({neff, {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};