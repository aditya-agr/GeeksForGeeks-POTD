/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool solve(int v, Node* root, string &s){
        if(!root)
            return false;
        if(root->data == v)
            return true;
        s.push_back('L');
        if(solve(v, root->left, s))
            return true;
        s.pop_back();
        s.push_back('R');
        if(solve(v, root->right, s))
            return true;
        s.pop_back();
        return false;
        
    }
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        string sp;
        string sq;
        solve(p, root, sp);
        solve(q, root, sq);
        int n = sp.length();
        int m = sq.length();
        
        int i=0;
        while(i<n && i<m && sp[i]==sq[i])
            i++;
            
        int turns = 0;
        for (int j = n - 1; j > i; j--) {
            if (sp[j] != sp[j - 1])
                turns++;
        }
        for (int j = i + 1; j < m; j++) {
            if (sq[j] != sq[j - 1])
                turns++;
        }
        if (i < n && i < m && sp[i] != sq[i])
            turns++;

        return turns == 0 ? -1 : turns;
    }
};