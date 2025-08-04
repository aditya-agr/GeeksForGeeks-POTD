class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int res = INT_MIN;
        for(int s=0; s<m; s++){
            vector<int> temp(n);
            for(int e=s; e<m; e++){
                for(int i=0; i<n; i++)
                    temp[i] += mat[i][e];
                
                int sum=0, mx=INT_MIN;
                for(int i=0; i<n; i++){
                    sum += temp[i];
                    mx = max(mx, sum);
                    if(sum < 0)
                        sum = 0;
                }
                res = max(res, mx);
            }
        }
        return res;
    }
};
