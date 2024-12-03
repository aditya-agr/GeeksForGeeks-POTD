class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        string comp = s;
        reverse(s.begin(), s.end());
        comp += "$";
        comp += s;
        int n = comp.size();
        vector<int> lps(n, 0);
        int i=0, j=1;
        while(j<n){
            if(comp[i]==comp[j])
                lps[j++] = ++i;
            else if(i!=0)
                i = lps[i-1];
            else
                j++;
        }
        return s.length()-i;
    }
};