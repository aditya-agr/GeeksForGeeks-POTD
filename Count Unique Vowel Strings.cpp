class Solution {
  public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int vowelCount(string& s) {
        // code here
        unordered_map<char, int> mp;
        for(char c : s){
            if(isVowel(c))
                mp[c]++;
        }
        if(mp.size() == 0)
            return 0;
        int n = mp.size();
        int fact = 1;
        while(n>=1){
            fact *= n;
            n--;
        }
        int res = 1;
        for(auto it : mp){
            res *= it.second;
        }
        return res*fact;
    }
    
};