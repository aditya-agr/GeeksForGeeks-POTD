class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        for(int i=0; i<=k; i++)
            pq.push(arr[i]);
        
        int x=0;
        for(int i=k+1; i<n; i++){
            arr[x++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        while(!pq.empty()){
            arr[x++] = pq.top();
            pq.pop();
        }
    }
};