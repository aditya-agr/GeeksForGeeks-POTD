class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        for(int i=0; i<k; i++)
            pq.push(arr[i]);
        
        vector<int> res(n,-1);
        for(int i=k; i<n; i++){
            res[i-1] = pq.top();
            pq.push(arr[i]);
            pq.pop();
        }
        res[n-1] = pq.top();
        return res;
    }
};