class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int> dq;
        int n = arr.size();
        for(int i=0; i<k; i++){
            while(!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();
            dq.push_back(i);
        }
        vector<int> res;
        res.push_back(arr[dq.front()]);
        for(int i=k; i<n; i++){
            while(!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();
            dq.push_back(i);
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            res.push_back(arr[dq.front()]);
        }
        return res;
    }
};