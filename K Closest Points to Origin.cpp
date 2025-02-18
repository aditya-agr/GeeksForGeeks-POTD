class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        priority_queue<vector<int>> pq;
        for(vector<int> i : points){
            int d = i[0]*i[0] + i[1]*i[1];
            pq.push({d, i[0], i[1]});
            if(pq.size()>k)
                pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            vector<int> it = pq.top();
            pq.pop();
            res.push_back({it[1], it[2]});
        }
        return res;
    }
};