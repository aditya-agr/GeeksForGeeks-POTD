class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size();
        int m = pat.size();
        int j = 0, i = 0, ast = -1, match = 0;
        while(i<n){
            if(j<m && (pat[j] == '?' || pat[j] == txt[i])){
                j++;
                i++;
            }
            else if(j<m && pat[j] == '*'){
                ast = j;
                match = i;
                j++;
            }
            else if(ast != -1){
                j = ast+1;
                match++;
                i = match;
            }
            else
                return false;
        }
        while(j<m && pat[j] == '*')
            j++;
        return j == m;
    }
};