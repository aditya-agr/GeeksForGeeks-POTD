class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0, down=n-1, left=0, right=m-1;
        vector<int> res;
        while(top<=down && left<=right){
            for(int i=left; i<=right; i++)
                res.push_back(matrix[top][i]);
            top++;
            for(int i=top; i<=down; i++)
                res.push_back(matrix[i][right]);
            right--;
            for(int i=right; top<=down && i>=left; i--)
                res.push_back(matrix[down][i]);
            down--;
            for(int i=down; left<=right && i>=top; i--)
                res.push_back(matrix[i][left]);
            left++;
        }
        return res;
    }
};