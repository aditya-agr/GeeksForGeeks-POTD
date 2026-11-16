class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            if(arr[i] <= k)
                k++;
            else
                break;
        }
        return k;
    }
};