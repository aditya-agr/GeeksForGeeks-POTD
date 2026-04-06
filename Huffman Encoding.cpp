struct Node{
    int freq;
    int idx;
    Node* left;
    Node* right;
    
    Node(int f, int i){
        freq = f;
        idx = i;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq == b->freq)
            return a->idx > b->idx;
        
        return a->freq > b->freq;
    }
};

class Solution {
  public:
    void preorder(Node* root, string code, vector<string> &ans){
        if(!root)
            return;
        
        if(!root->left && !root->right){
            ans.push_back(code);
            return;
        }
        preorder(root->left, code+"0", ans);
        preorder(root->right, code+"1", ans);
    }
    vector<string> huffmanCodes(string &s, vector<int> f) {
        // Code h ;ere
        int n = s.size();
        if(n == 1)
            return {"0"};

        priority_queue<Node*, vector<Node*>, Compare> pq;
        for(int i=0; i<n; i++){
            Node* cur = new Node(f[i], i);
            pq.push(cur);
        }
        while(pq.size()>1){
            Node* a = pq.top();
            pq.pop();
            Node* b = pq.top();
            pq.pop();
            Node* cur = new Node(a->freq+b->freq, min(a->idx, b->idx));
            cur->left = a;
            cur->right = b;
            pq.push(cur);
        }
        vector<string> ans;
        preorder(pq.top(), "", ans);
        return ans;
    }
};