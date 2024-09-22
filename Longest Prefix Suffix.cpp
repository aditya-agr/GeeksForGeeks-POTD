class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int n = str.size();
        vector<int> idx(n);
        int i=0, j=1;
        while(j<n){
            if(str[i]==str[j]){
                i++;
                idx[j] = i;
                j++;
            }
            else{
                if(i>0)
                    i = idx[i-1];
                else
                    j++;
            }
        }
        return idx[n-1];
    }
};