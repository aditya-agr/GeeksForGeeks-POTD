class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        vector<pair<int, int>> vec;
        int n = arr.size();
        for(int i=0; i<n; i++)
            vec.push_back({arr[i], i});
        
        sort(vec.begin(), vec.end());
        priority_queue<int> pq;
        pq.push(vec[0].second);
        
        vector<int> res(n);
        res[vec[0].second] = -1;
        for(int i=1; i<n; i++){
            if(pq.top() > vec[i].second)
                res[vec[i].second] = pq.top();
            else
                res[vec[i].second] = -1;
            pq.push(vec[i].second);
        }
        return res;
    }
};