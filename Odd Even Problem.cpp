class Solution {
  public:
    string oddEven(string s) {
        // code here
        vector<int> idx(26);
        for(auto &c: s)
            idx[c-'a']++;
        int cnt=0;
        for(int i=0; i<26; i++){
            if((i+1)%2==0 && idx[i]!=0 && idx[i]%2==0)
                cnt++;
            if((i+1)%2 && idx[i]%2)
                cnt++;
        }
        return (cnt%2) ? "ODD" : "EVEN";
    }
};
