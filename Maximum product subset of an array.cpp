class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        if(arr.size()==1)
            return arr[0];
        long long int pos=1, neg=1, mx=INT_MIN;
        long long int mod=1e9+7, cn=0, cp=0;
        for(long long int i : arr){
            if(i<0){
                mx = max(i, mx);
                neg = (neg*i)%mod;
                cn++;
            }
            if(i>0){
                pos = (pos*i)%mod;
                cp++;
            }
        }
        if(cn<=1 && cp==0)
            return 0;
        if(neg < 0)
            neg /= mx;
        
        return (pos*neg)%mod;
    }
};