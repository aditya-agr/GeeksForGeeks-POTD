class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> base(23);
        for(int i=0; i<n; i++){
            int x = arr[i];
            for(int j=22; j>=0; j--){
                if(x&(1<<j)){
                    if(base[j]&(1<<j))
                        x ^= base[j];
                    else{
                        base[j] = x;
                        break;
                    }
                }
            }
        }
        int res = 0;
        for(int i=22; i>=0; i--){
            if(!(res&(1<<i)))
                res ^= base[i];
        }
        return res;
    }
};