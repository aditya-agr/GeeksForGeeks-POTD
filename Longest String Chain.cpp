class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        auto comp = [](string &a, string &b){
            if(a.size() < b.size())
                return true;
            return false;
        };
        sort(words.begin(), words.end(), comp);
        unordered_map<string, int> mp;
        int maxLength = 1;
        for(string s : words){
            int len = 1;
            int n = s.size();
            for(int i=0; i<n; i++){
                string curr = s.substr(0, i) + s.substr(i+1);
                if(mp[curr])
                    len = max(len, mp[curr]+1);
            }
            mp[s] = len;
            maxLength = max(maxLength, len);
        }
        return maxLength;
    }
};
