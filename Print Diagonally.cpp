class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n = mat.size();
        int i=0, j=0; 
        vector<int> res;
        while(i<n && j<n){
            int x=i, y=j;
            while(x<n && y>=0){
                res.push_back(mat[x][y]);
                x++;
                y--;
            }
            if(j+1<n) j++;
            else    i++;
        }
        return res;
    }
};