class Solution {
  public:
    // Function to find a solved Sudoku.
    bool satisfy(int k, int i, int j, vector<vector<int>> &mat){
        for(int x=0; x<9; x++)
            if(mat[i][x] == k || mat[x][j] == k)
                return false;
        int sr = i-i%3;
        int sc = j-j%3;
        for(int r=0; r<3; r++){
            for(int c=0; c<3; c++)
                if(mat[sr+r][sc+c] == k)
                    return false;
        }
        return true;
    }
    bool solve(vector<vector<int>> &mat) {
        // code here
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(mat[i][j] == 0){
                    for(int k=1; k<=9; k++){
                        if(satisfy(k, i, j, mat)){
                            mat[i][j] = k;
                            if(solve(mat))
                                return true;
                            mat[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
    }
};