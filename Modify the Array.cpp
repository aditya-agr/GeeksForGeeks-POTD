class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        int n = arr.size();
        vector<int> res(n);
        int j=0;
        for(int i=0; i<n-1; i++){
            if(arr[i] != 0){
                if(arr[i] == arr[i+1]){
                    i++;
                    res[j++] = 2*arr[i];
                }
                else
                    res[j++] = arr[i];
            }
        }
        if(arr[n-1] != arr[n-2])
            res[j++] = arr[n-1];
        return res;
    }
};