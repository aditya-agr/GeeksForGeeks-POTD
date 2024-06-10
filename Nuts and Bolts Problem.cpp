class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        // sort(nuts, nuts+n);
        // sort(bolts, bolts+n);
        
        // code here
        char ch[] = {'!','#','$','%','&','*','?','@','^'};
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++)
            mp[nuts[i]]++;
        for(int i=0, j=0; i<9; i++){
            if(mp[ch[i]]){
                nuts[j] = ch[i];
                bolts[j] = ch[i];
                j++;
            }
        }
    }
};