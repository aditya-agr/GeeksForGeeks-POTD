class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        int n = arr.size();
        vector<int> res(n);
        int l = 0;
        int r = n-1;
        int i = (A>=0) ? n-1 : 0;
        while(l<=r){
            int left = A*arr[l]*arr[l] + B*arr[l] + C;
            int right = A*arr[r]*arr[r] + B*arr[r] + C;
            if(A>=0){
                if(left < right){
                    res[i] = right;
                    i--;
                    r--;
                }
                else{
                    res[i] = left;
                    i--;
                    l++;
                }
            }
            else{
                if(left > right){
                    res[i] = right;
                    i++;
                    r--;
                }
                else{
                    res[i] = left;
                    i++;
                    l++;
                }
            }
        }
        return res;
    }
};