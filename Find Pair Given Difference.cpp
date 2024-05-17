class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int i=0, j=1;
        while(i<=j){
            if(abs(arr[i]-arr[j]) == x)
                return 1;
            else if(abs(arr[i]-arr[j]) < x)
                j++;
            else
                i++;
        }
        return -1;
    }
};