class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans=0, zero=0, one=0;
        for (int i=0; i<n; i++){
            if (!arr[i]) {
                zero++;
            }
            else {
                zero--;
                one++;
            }
            ans=max(zero, ans);
            //cout<<one<<" "<<zero<<" "<<ans<<endl;
            if (zero<0) {
                zero=0;
            }
        }
        return ans+one;
    }
};