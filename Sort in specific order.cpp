class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i=0, j=n-1;
        while(i<j){
            while(i<n && arr[i]%2 == 1)
                i++;
            if(i==n){
                sort(arr.rbegin(), arr.rend());
                return;
            }
            while(j>=0 && arr[j]%2 == 0)
                j--;
            if(j == -1){
                sort(arr.begin(), arr.end());
                return;
            }
            if(i<j) 
                swap(arr[i], arr[j]);
        }
        int pivot = i;
        sort(arr.begin(), arr.begin()+i);
        reverse(arr.begin(), arr.begin()+i);
        sort(arr.begin()+i, arr.end());
    }
};