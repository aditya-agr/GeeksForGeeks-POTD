class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res(n);
        int cnt = -1;
        long long sum = 1;
        for(int i=0; i<n; i++){
            if(arr[i]) sum *= arr[i];
            else{
                if(cnt==-1) cnt = i;
                else return res;
            }
        }
        if(cnt!=-1){
            res[cnt] = sum;
            return res;
        } 
        for(int i=0; i<n; i++)
            res[i] = sum/arr[i];
        return res;
    }
};