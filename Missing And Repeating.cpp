class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int> res(2);
        int n = arr.size();
        for(int i=0; i<n; i++){
            int idx = abs(arr[i])-1;
            if(arr[idx]<0)
                res[0] = abs(arr[i]);
            else
                arr[idx] *= -1;
        }
        for(int i=0; i<n; i++)
            if(arr[i]>0)
                res[1] = i+1;
        return res;
    }
};