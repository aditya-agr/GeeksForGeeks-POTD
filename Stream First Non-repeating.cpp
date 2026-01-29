class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        queue<char> q;
        string res = "";
        vector<int> freq(26);
        for(char c : s){
            freq[c-'a']++;
            if(freq[c-'a'] == 1)
                q.push(c);
            while(!q.empty() && freq[q.front()-'a'] != 1)
                q.pop();
            
            if(!q.empty())
                res += q.front();
            else
                res += "#";
        }
        return res;
    }
};