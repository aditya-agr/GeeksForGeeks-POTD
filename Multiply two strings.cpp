class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        bool neg = false;
        if(s1[0] == '-'){
            neg = !neg;
            s1 = s1.substr(1);
        }
        if(s2[0] == '-'){
            neg = !neg;
            s2 = s2.substr(1);
        }
        int n = s1.size();
        int m = s2.size();
        vector<int> res(n+m);
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res[i+j] += (s1[i]-'0')*(s2[j]-'0');
                res[i+j+1] += res[i+j]/10;
                res[i+j] %= 10;
            }
        }
        string ans = "";
        bool zero = false;
        for(int i=n+m-1; i>=0; i--){
            if(res[i] != 0) zero = true;
            if(zero) ans += ('0'+res[i]);
        }
        if(ans.empty())
            return "0";
        if(neg)
            ans = '-'+ans;
        return ans;
    }
};