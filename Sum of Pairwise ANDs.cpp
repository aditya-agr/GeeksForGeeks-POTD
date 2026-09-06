class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        vector<int> bit(32);
        long long sum = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<32; j++){
                long long cur = arr[i]&(1<<j);
                if(bit[j])
                    sum += bit[j]*cur*1LL;
                if(cur)
                    bit[j]++;
            }
        }
        return sum;
    }
};