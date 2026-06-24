class Solution {
  public:
    vector<vector<int>> dp;
	
	bool withInMatrix(int i, int j, vector<vector<int>> & mat) {
		if (i >= mat.size() || j >= mat[0].size() || mat[i][j] == 0) {
			return false;
		}
		
		return true;
	}
	bool ratmaze(vector<vector<int>> & mat, vector<vector<int>> & ans, int i, int j) {
		if (!withInMatrix(i, j, mat))
			return false;
		
		if (i == mat.size() - 1 && j == mat[0].size() - 1) {
			ans[i][j] = 1;
			return true;
		}
		
		if (dp[i][j] == 0)
			return false;
		
		ans[i][j] = 1;
		
		for (int jump = 1; jump <= mat[i][j]; jump++) {
			if (ratmaze(mat, ans, i, j + jump))
				return true;
			
			if (ratmaze(mat, ans, i + jump, j))
				return true;
		}
		
		ans[i][j] = 0;
		dp[i][j] = 0;
		
		return false;
	}
	
	vector<vector<int>> shortestDist(vector<vector<int>> & mat) {
		// code here
		vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
		dp.assign(mat.size(), vector<int>(mat[0].size(), -1));
		if (!ratmaze(mat, ans, 0, 0)) {
			return {{-1}};
		}
		return ans;
	}
};