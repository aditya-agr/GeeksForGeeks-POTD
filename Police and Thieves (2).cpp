class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size();
        int cnt = 0;
        int i = 0, j = 0;
        while(i < n && j<n){
            while(i<n && arr[i] != 'P')
                i++;
            while(j<n && arr[j] != 'T')
                j++;
            if(i<n && j<n && abs(j-i)<=k){
                cnt++;
                i++;
                j++;
            }
            else if(i<n && i<j)
                i++;
            else
                j++;
        }
        return cnt;
        
        
    }
};