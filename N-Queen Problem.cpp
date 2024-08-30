class Solution{
public:
    bool canPut(int r, int c, vector<int> &ans){
        int row=r, col=c;
        while(row>=0 && col>=0){
            if(ans[row] == col+1)
                return false;
            row--;
            col--;
        }
        row=r, col=c;
        while(row>=0){
            if(ans[row] == col+1)
                return false;
            row--;
        }
        row=r, col=c;
        while(row>=0 && col<ans.size()){
            if(ans[row] == col+1)
                return false;
            row--;
            col++;
        }
        return true;
    }
    void solve(int row, int n, vector<int> &ans, vector<vector<int>> &res){
        if(row == n){
            res.push_back(ans);
            return;
        }
        for(int col=0; col<n; col++){
            if(canPut(row, col, ans)){
                ans[row] = col+1;
                solve(row+1, n, ans, res);
                ans[row] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> res;
        vector<int> ans(n);
        solve(0, n, ans, res);
        return res;
    }
};