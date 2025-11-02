class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        int E = edges.size();
        int tot = V*(V-1)/2;
        return tot - E;
    }
};
