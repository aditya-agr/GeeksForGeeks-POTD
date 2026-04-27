class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        vector<int> cnt(3);
        int dist = 0;
        int n = s.length();
        int i=0, j=0;
        int res = INT_MAX;
        while(j<n){
            if(cnt[s[j]-'0'] == 0)
                dist++;
            cnt[s[j]-'0']++;
    
            while(dist == 3){
                res = min(res, j-i+1);
                cnt[s[i]-'0']--;
                if(cnt[s[i]-'0'] == 0)
                    dist--;
                i++;
            }
            j++;
        }
        return res==INT_MAX ? -1 : res;
    }
};
