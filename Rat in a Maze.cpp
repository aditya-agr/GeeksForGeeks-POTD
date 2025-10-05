class Solution {
  public:
    vector<string> res;
    void solve(int i, int j, string cur, vector<vector<int>> &maze){
        int n = maze.size();
        if(i>=n || i<0 || j>=n || j<0 || maze[i][j]==0)
            return;
        if(i==n-1 && j==n-1){
            res.push_back(cur);
            return;
        }
        maze[i][j] = 0;
        solve(i+1, j, cur+"D", maze);
        solve(i, j-1, cur+"L", maze);
        solve(i, j+1, cur+"R", maze);
        solve(i-1, j, cur+"U", maze);
        maze[i][j] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        string cur="";
        solve(0, 0, cur, maze);
        // sort(res.begin(), res.end());
        return res;
    }
};