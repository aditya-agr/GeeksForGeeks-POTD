class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i=0; i<n; i++){
            pq.push({mat[i][0], {i, 0}});
        }
        int k = n*m/2;
        while(k--){
            int val = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(col < m-1)
                pq.push({mat[row][col+1], {row, col+1}});
        }
        return pq.top().first;
    }
};
