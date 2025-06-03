class Solution {
  public:
    int solve(string &s, int k){
        unordered_map<char, int> mp;
        int cnt = 0;
        int res = 0;
        int n = s.length();
        int j=0;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            if(mp[s[i]] == 1)
                cnt++;
            while(cnt > k){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    cnt--;
                j++;
            }
            res+=i-j+1;
        }
        return res;
    }
    int countSubstr(string& s, int k) {
        // code here.
        int a = solve(s, k);
        int b = solve(s, k-1);
        return a-b;
    }
};