class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        q.push({knightPos[0]-1, knightPos[1]-1});
        dp[knightPos[0]-1][knightPos[1]-1] = 0;
        
        vector<vector<int>> dir = {{1,2}, {1,-2}, {2,1}, {-2,1},
                                    {-1,2}, {-1,-2}, {2,-1}, {-2,-1}};
        
        if(knightPos[0]==targetPos[0] && knightPos[1]==targetPos[1])
            return 0;
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(vector<int> &d : dir){
                int x_ = x+d[0];
                int y_ = y+d[1];
                if(x_<0 || x_>=n || y_<0 || y_>=n || dp[x_][y_] != INT_MAX)
                    continue;
                if(x_==targetPos[0]-1 && y_==targetPos[1]-1)
                    return dp[x][y]+1;
                dp[x_][y_] = dp[x][y]+1;
                q.push({x_, y_});
            }
        }
        return -1;
    }
};