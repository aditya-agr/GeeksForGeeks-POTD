class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code her
        vector<int> res;
        int n = mat.size();
        int m = mat[0].size();
        int l=0, r=m-1, u=0, d=n-1;
        while(l<=r && u<=d){
            for(int i=l; i<=r; i++)
                res.push_back(mat[u][i]);
            u++; 
            if(l>r || u>d) break;
            for(int i=u; i<=d; i++)
                res.push_back(mat[i][r]);
            r--;
            if(l>r || u>d) break;
            for(int i=r; i>=l; i--)
                res.push_back(mat[d][i]);
            d--;
            if(l>r || u>d) break;
            for(int i=d; i>=u; i--)
                res.push_back(mat[i][l]);
            l++;
            if(l>r || u>d) break;
        }
        return res;
        
    }
};