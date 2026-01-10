class Solution {
  public:
    int cntatmostK(string &s, int k){
        int i=0, j=0;
        int n = s.length();
        vector<int> freq(26);
        int dist = 0, res = 0;
        while(j<n){
            freq[s[j]-'a']++;
            if(freq[s[j]-'a'] == 1)
                dist++;
            while(dist > k){
                freq[s[i]-'a']--;
                if(freq[s[i]-'a'] == 0)
                    dist--;
                i++;
            }
            res += j-i+1;
            j++;
        }
        return res;
    }
    int countSubstr(string& s, int k) {
        // code here
        if(k == 1){
            return cntatmostK(s, k);
        }
        return cntatmostK(s, k) - cntatmostK(s, k-1);
    }
};