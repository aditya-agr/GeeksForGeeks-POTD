class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int i=0, j=0, k=arr.size()-1;
        while(j<=k){
            if(arr[j]==0){
                swap(arr[i], arr[j]);
                i++;
                j++;
            }
            else if(arr[j]==1)
                j++;
            else{
                swap(arr[j], arr[k]);
                k--;
            }
        }
    }
};