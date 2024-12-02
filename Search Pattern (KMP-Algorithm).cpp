class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        int n = pat.size();
        vector<int> lps(n, 0);
        for(int i=1; i<n; i++){
            int j = lps[i-1];
            while(j>0 && pat[i]!=pat[j])
                j = lps[j-1];
            if(pat[i] == pat[j])
                j++;
            lps[i] = j;
        }
        int m = txt.size();
        int i = 0;
        int j = 0;
        vector<int> res;
        while (i < m) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
                if (j == n) {
                    res.push_back(i - j);
                    j = lps[j - 1];
                }
            }
            else {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return res;
    }
};