class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int i=0, j=0, c=1;
        int n=a.size(), m=b.size();
        while(i<n && j<m){
            if(a[i]<b[j]){
                if(c==k)
                    return a[i];
                i++;
            }
            else{
                if(c==k)
                    return b[j];
                j++;
            }
            c++;
        }
        while(i<n){
            if(c==k)
                return a[i];
            c++;
            i++;
        }
        while(j<m){
            if(c==k)
                return b[j];
            c++;
            j++;
        }
        return -1;
    }
};