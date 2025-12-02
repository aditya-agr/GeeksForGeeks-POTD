class TrieNode{
  public:
    TrieNode* child0;
    TrieNode* child1;
    int cnt;
    
    TrieNode(){
        child0 = NULL;
        child1 = NULL;
        cnt = 0;
    }
};

class Solution {
  public:
    void add(TrieNode* root, int num){
        TrieNode* curr = root;
        for(int i=16; i>=0; i--){
            int bit = num&(1<<i);
            if(bit==0){
                if(!curr->child0)
                    curr->child0 = new TrieNode();
                curr = curr->child0;
            }
            else{
                if(!curr->child1)
                    curr->child1 = new TrieNode();
                curr = curr->child1;
            }
            curr->cnt++;
        }
    }
    int query(TrieNode* root, int num, int k){
        TrieNode* curr = root;
        int res = 0;
        for(int i=16; i>=0; i--){
            if(!curr)
                break;
            int kbit = k&(1<<i);
            int nbit = num&(1<<i);
            if(kbit > 0){
                if(nbit == 0){
                    if(curr->child0)
                        res += curr->child0->cnt;
                    curr = curr ->child1;
                }
                else{
                    if(curr->child1)
                        res += curr->child1->cnt;
                    curr = curr ->child0;
                }
            }
            else{
                if(nbit == 0)
                    curr = curr->child0;
                else
                    curr = curr->child1;
            }
        }
        return res;
    }
    int cntPairs(vector<int>& arr, int k) {
        // code here
        TrieNode* root = new TrieNode();
        int res = 0;
        for(int x : arr){
            res += query(root, x, k);
            add(root, x);
        }
        return res;
    }
};