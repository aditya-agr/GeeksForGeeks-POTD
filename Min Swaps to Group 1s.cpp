class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int cnt = 0;
        int n = arr.size();
        for(int i=0; i<n; i++)
            cnt += arr[i];
        
        if(cnt == 0)
            return -1;
        
        int cur = 0;
        for(int i=0; i<cnt; i++)
            cur += arr[i];
            
        int res = cnt-cur;
        for(int i=cnt; i<n; i++){
            cur += arr[i];
            cur -= arr[i-cnt];
            res = min(res, cnt-cur);
        }
        return res;
    }
};