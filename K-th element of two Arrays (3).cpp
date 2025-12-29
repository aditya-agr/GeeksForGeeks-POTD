class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n = a.size();
        int m = b.size();
        int i=0, j=0, cnt=0;
        int res = 0;
        while(i<n && j<m){
            if(a[i]<b[j])
                res = a[i++];
            else
                res = b[j++];
            cnt++;
            if(cnt == k)
                return res;
        }
        while(i<n){
            cnt++;
            if(cnt == k)
                return a[i];
            i++;
        }
        while(j<m){
            cnt++;
            if(cnt == k)
                return b[j];
            j++;
        }
        return -1;
    }
};