class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        vector<int> freq(26);
        int dist = 0, res = -1;
        int i=0, j=0;
        int n = s.length();
        while(j<n){
            int idx = s[j] - 'a';
            if(freq[idx] == 0)
                dist++;
            freq[idx]++;
            
            while(dist > k){
                int idx = s[i] - 'a';
                freq[idx]--;
                if(freq[idx] == 0)
                    dist--;
                    i++;
            }
            if(dist == k)
                res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};