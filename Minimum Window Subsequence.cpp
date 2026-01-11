class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n = s1.size();
        int m = s2.size();
        int mn = INT_MAX, idx = -1;
        
        for(int i=0; i<n; i++){
            if(s1[i] == s2[0]){
                int k = i, j = 0;
                while(k<n && j<m){
                    while(k<n && s1[k]!=s2[j])
                        k++;
                    if(k>=n) break;
                    j++;
                    k++;
                }
                if(j==m){
                    int sz = k-i;
                    if(sz < mn){
                        mn = sz; 
                        idx = i;
                    }
                }
            }
        }
        
        return (idx != -1) ? s1.substr(idx, mn) : "";
    }
};
