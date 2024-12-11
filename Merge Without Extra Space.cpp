class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        int i=n-1, j=0;
        while(i<n && j<m){
            if(b[j] < a[i])
                swap(b[j++], a[i--]);
            else 
                break;
        }
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());
    }
};