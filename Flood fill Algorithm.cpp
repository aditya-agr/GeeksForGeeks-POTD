class Solution {
  public:
    vector<vector<int>> directions = {{0,1}, {0,-1},{1,0},{-1,0}};
    void solve(vector<vector<int>>& image, int i, int j,
        int &newColor, int &originalColor){
            int n = image.size();
            int m = image[0].size();
            if(i>=n || i<0 || j>=m || j<0 || image[i][j]!=originalColor)
                return;
            image[i][j] = newColor;
            for(vector<int> d : directions){
                int i_ = i+d[0];
                int j_ = j+d[1];
                solve(image, i_, j_, newColor, originalColor);
            }
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int originalColor = image[sr][sc];
        if(originalColor != newColor)
            solve(image, sr, sc, newColor, originalColor);
        return image;
    }
};