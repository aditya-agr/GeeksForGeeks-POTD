
// User function template for C++
class TrieNode{
  public:
    vector<TrieNode*> child;
    bool end;
    TrieNode(){
        child.resize(26);
        end = false;
        for(int i=0; i<26; i++)
            child[i] = NULL;
    }
};
// implement Trie
class Trie {
  public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        // insert word into Trie
        TrieNode* crawler = root;
        for(char c : word){
            int i = c-'a';
            if(crawler->child[i] == NULL)
               crawler->child[i] = new TrieNode();
            crawler = crawler->child[i];
        }
        crawler->end = true;
    }

    bool search(string &word) {
        // search word in the Trie
        TrieNode* crawler = root;
        for(char c : word){
            int i = c-'a';
            if(crawler->child[i] == NULL)
               return false;
            crawler = crawler->child[i];
        }
        return crawler->end;
        
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        TrieNode* crawler = root;
        for(char c : word){
            int i = c-'a';
            if(crawler->child[i] == NULL)
               return false;
            crawler = crawler->child[i];
        }
        return true;
    }
};