class Solution {
  public:
    int n, m, l;
    vector<vector<int>> dir = {{0,-1}, {0,1}, {1,0}, {-1,0}};
    bool solve(vector<vector<char>>& mat, string& word, int i, int j, int s){
        if(s == l)
            return true;
        if(i<0 || i>=n || j<0 || j>=m || mat[i][j] == '#' || mat[i][j]!=word[s])
            return false;
        mat[i][j] = '#';
        for(auto d : dir){
            int i_ = i+d[0];
            int j_ = j+d[1];
            if(solve(mat, word, i_, j_, s+1)){
                return true;
            }
        }
        mat[i][j] = word[s];
        return false;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        n = mat.size();
        m = mat[0].size();
        l = word.length();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == word[0]){
                    bool curr = solve(mat, word, i, j, 0);
                    if(curr) return true;
                }
            }
        }
        return false;
    }
};