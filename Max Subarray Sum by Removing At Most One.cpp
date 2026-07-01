class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sumNoDel = arr[0], sumDel = -1e9;
        int res = arr[0];
        for(int i=1; i<n; i++){
            int curSumNoDel = max(sumNoDel+arr[i], arr[i]);
            res = max(res, curSumNoDel);
            int curSumDel = max(sumDel+arr[i], sumNoDel);
            res = max(res, curSumDel);
            
            sumDel = curSumDel;
            sumNoDel = curSumNoDel;
        }
        return res;
    }
};