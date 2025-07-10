class Solution {
  public:
    bool solve(string &s, unordered_set<string> &st, unordered_map<string, bool> &mp){
        int n = s.length();
        if(n == 1)
            return mp[s] = st.count(s);
        if(mp.count(s))
            return mp[s];
        string sub = s.substr(0, n-1);
        if(st.count(s) && solve(sub, st, mp))
            return mp[s] = true;
        else
            return mp[s] = false;
    }
    string longestString(vector<string> &words) {
        // code here
        unordered_set<string> st(words.begin(), words.end());
        unordered_map<string, bool> mp;
        string res = "";
        int mxlen = 0;
        int n = words.size();
        for(int i=0; i<n; i++){
            if(solve(words[i], st, mp)){
                if(words[i].length() > mxlen){
                    mxlen = words[i].length();
                    res = words[i];
                }
                else if(words[i].length() == mxlen)
                    res = min(res, words[i]);
            }
        }
        return res;
    }
};


class TrieNode{
  public:
    vector<TrieNode*> children;
    bool end;
    
    TrieNode(){
        children.resize(26);
        for(int i=0; i<26; i++)
            this->children[i] = NULL;
        this->end = false;
    }
};

class Solution {
  public:
    TrieNode *root;
    void insert(string &s){
        TrieNode *crawler = root;
        for(char c : s){
            if(crawler->children[c-'a'] == NULL)
                crawler->children[c-'a'] = new TrieNode();
            crawler = crawler->children[c-'a'];
        }
        crawler->end = true;
    }
    bool search(string &s){
        TrieNode *crawler = root;
        for(char c : s){
            crawler = crawler->children[c-'a'];
            if(crawler->end == false)
                return false;
        }
        return true;
    }
    string longestString(vector<string> &words) {
        // code here
        root = new TrieNode();
        for(string s : words)
            insert(s);
        
        string res = "";
        int mxlen = 0;
        for(string s : words){
            if(search(s)){
                if(s.length() > mxlen){
                    mxlen = s.length();
                    res = s;
                }
                if(s.length() == mxlen)
                    res = min(s, res);
            }
        }
        return res;
    }
};