class Solution {
  public:
    int countgroup(vector<int>& arr) {
        // Complete the function
        int xr = 0;
        for(int x : arr)
            xr ^= x;
        
        if(xr)
            return 0;
            
        int mod = 1e9+7;
        long long res=1;
        int n = arr.size();
        for(int i=0; i<n-1; i++)
            res = (res*2)%mod;
        res = (res-1+mod)%mod;
        return res;
        
    }
};