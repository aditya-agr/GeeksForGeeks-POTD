#define P pair<int, pair<int, int>>
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++)
            pq.push({matrix[i][0], {i, 0}});
        
        int cnt = 0;
        int val = 0;
        while(cnt != k){
            val = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(j<m-1)
                pq.push({matrix[i][j+1], {i, j+1}});
            cnt++;
        }
        return val;
    }
};