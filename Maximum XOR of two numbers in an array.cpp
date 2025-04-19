class TrieNode{
  public:
    TrieNode *one, *zero;
    TrieNode(){
        one = NULL;
        zero = NULL;
    }
};

class Trie{
  public:
    TrieNode *root;
    Trie(){
        root = new TrieNode();
    }
    void insert(int num){
        TrieNode *crawler = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(bit == 0){
                if(crawler->zero == NULL)
                    crawler->zero = new TrieNode();
                crawler = crawler->zero;
            }
            if(bit == 1){
                if(crawler->one == NULL)
                    crawler->one = new TrieNode();
                crawler = crawler->one;
            }
        }
    }
    int search(int num){
        int res = 0;
        TrieNode *crawler = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(bit == 0){
                if(crawler->one){
                    crawler = crawler->one;
                    res += (1<<i);
                }
                else    
                    crawler = crawler->zero;
            }
            if(bit == 1){
                if(crawler->zero){
                    res += (1<<i);
                    crawler = crawler->zero;
                }
                else
                    crawler = crawler->one;
            }
        }
        return res;
    }
};

class Solution {
  public:
    int maxXor(vector<int> &arr) {
        // code here
        int res = 0;
        Trie* tr = new Trie();
        tr->insert(arr[0]);
        
        int n = arr.size();
        for(int i=1; i<n; i++){
            int curr = tr->search(arr[i]);
            res = max(res, curr);
            tr->insert(arr[i]);
        }
        return res;
    }
};
