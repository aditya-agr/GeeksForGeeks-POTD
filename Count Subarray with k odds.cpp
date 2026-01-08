class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> odd;
        for(int i=0; i<n; i++)
            if(arr[i]%2)
                odd.push_back(i);
        
        int m = odd.size();
        if(m == 0 || k > m)
            return 0;
        if(m == k)
            return (odd[0]+1)*(n-odd[m-1]);
            
        int res = (odd[0]+1)*(odd[k]-odd[k-1]);
        for(int i=k; i<m-1; i++){
            res += (odd[i-k+1]-odd[i-k])*(odd[i+1]-odd[i]); 
        }
        res += (odd[m-1-k+1]-odd[m-1-k])*(n-odd[m-1]);
        return res;
    }
};