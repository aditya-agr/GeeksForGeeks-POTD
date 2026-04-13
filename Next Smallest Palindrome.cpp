class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        // code here
        int n = num.size();
        vector<int> res = num;
        int change = 1;
        for(int i=0; i<n/2; i++){
            if(res[i] > res[n-i-1])
                change = 0;
            if(res[i] < res[n-i-1])
                change = 1;
            res[n-i-1] = res[i];
        }
        int idx = n/2;
        while(change && idx<n){
            if(res[idx] == 9){
                res[idx] = 0;
                res[n-1-idx] = 0;
            }
            else{
                res[idx] += 1;
                res[n-1-idx] = res[idx];
                change = 0;
            }
            idx++;
        }
        if(change){
            res[0] = 1;
            res.push_back(1);
        }
        return res;
    }
};