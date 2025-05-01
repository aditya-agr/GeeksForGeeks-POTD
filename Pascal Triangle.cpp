class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<int> res(n, 1);
        for(int i=2; i<n; i++){
            for(int j=i-1; j>=1; j--)
                res[j] += res[j-1];
        }
        return res;
    }
};
