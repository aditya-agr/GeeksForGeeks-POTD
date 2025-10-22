class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> res;
        int n = arr.size();
        for(int i=0; i<=k; i++)
            pq.push(arr[i]);
        
        for(int i=k+1; i<n; i++){
            res.push_back(pq.top());
            pq.pop();
            pq.push(arr[i]);
        }
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        arr = res;
    }
};