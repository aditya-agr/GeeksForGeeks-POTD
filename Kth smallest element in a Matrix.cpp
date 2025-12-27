class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        for(int i=0; i<n; i++){
            pq.push({mat[i][0], {i, 0}});
        }
        k--;
        while(k--){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(c<m-1)
                pq.push({mat[r][c+1], {r, c+1}});
        }
        return pq.top().first;
    }
};
