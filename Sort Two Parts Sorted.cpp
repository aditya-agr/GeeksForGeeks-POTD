class Solution {
  public:
    void mergeTwoParts(vector<int>& arr) {
        // code here
        int n = arr.size();
        int idx = n;
        for(int i=1; i<n; i++){
            if(arr[i] < arr[i-1]){
                idx = i;
                break;
            }
        }
        if(idx == n)
            return;
        vector<int> res;
        int i=0, j=idx;
        while(i<idx && j<n){
            if(arr[i] < arr[j])
                res.push_back(arr[i++]);
            else
                res.push_back(arr[j++]);
        }
        while(i<idx){
            res.push_back(arr[i++]);
        }
        while(j<n){
            res.push_back(arr[j++]);
        }
        arr = res;
    }
};