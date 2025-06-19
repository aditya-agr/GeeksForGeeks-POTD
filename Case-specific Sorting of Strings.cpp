class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<int> lower(26), upper(26);
        for(char c : s){
            if(c >= 'a' && c<='z')
                lower[c-'a']++;
            else
                upper[c-'A']++;
        }
        int n = s.size();
        int u=0, l=0;
        for(int i=0; i<n; i++){
            if(s[i]>='a' && s[i]<='z'){
                while(lower[l]==0) l++;
                s[i] = char(l+'a');
                lower[l]--;
            }
            else{
                while(upper[u]==0) u++;
                s[i] = char(u+'A');
                upper[u]--;
            }
        }
        return s;
    }
};