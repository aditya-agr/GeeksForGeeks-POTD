
class Solution {
  public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<char> path = {'U','D','L','R'};
    
    void solve(vector<vector<int>> &mat, int i, int j, string &s, vector<string> &res){
        int n = mat.size();
        if(i<0 || i>=n || j<0 || j>=n || mat[i][j]==0)
            return;
        if(i==n-1 && j==n-1){
            res.push_back(s);
            return;
        }
        mat[i][j]=0;
        for(int k=0; k<4; k++){
            int ni = i+dir[k][0];
            int nj = j+dir[k][1];
            s.push_back(path[k]);
            solve(mat, ni, nj, s, res);
            s.pop_back();
        }
        mat[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> res;
        string s="";
        solve(mat, 0, 0, s, res);
        return res;
    }
};