class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int> dq;
        int n = arr.size();
        vector<int> res;
        for(int i=0; i<n; i++){
            while(!dq.empty() && arr[dq.back()]<=arr[i])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k-1){
                while(dq.front() <= i-k)
                    dq.pop_front();
                res.push_back(arr[dq.front()]);
            }
        }
        return res;
    }
};