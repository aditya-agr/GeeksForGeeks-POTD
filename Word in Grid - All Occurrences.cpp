class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        vector<vector<int>> res;
        int n = mat.size();
        int m = mat[0].size();
        int s = word.length();
        vector<vector<int>> dir = {{0,1}, {1,1}, {1,0}, {1,-1}, 
        {0,-1}, {-1,-1},{-1,0}, {-1,1}}; 
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                bool pos = false;
                for(vector<int> &d : dir){
                    int di = d[0];
                    int dj = d[1];
                    int x = i, y = j;
                    int k = 0;
                    while(mat[x][y] == word[k]){
                        x += di;
                        y += dj;
                        k += 1;
                        if(k == s){
                            pos = true;
                            break;
                        }
                        if(x<0 || x>=n || y<0 || y>=m)
                            break;
                    }
                    if(pos)
                        break;
                }
                if(pos)
                    res.push_back({i, j});
            }
        }
        return res;
    }
};