class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0, j=n-1;
        while(i<=j){
            while(i<=j && arr[i]==0)
                i++;
            while(i<=j && arr[j]!=0)
                j--;
            swap(arr[i], arr[j]);
        }
    }
};