class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int i=0, j=1;
        while(i<n && j<n){
            if(abs(arr[i]-arr[j]) == x)
                return 1;
            else if(abs(arr[i]-arr[j]) < x)
                j++;
            else
                i++;
            if(i==j)
                j++;
        }
        return -1;
    }
};