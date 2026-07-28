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
};*/

class Solution {
  public:
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        // code here
        unordered_map<int,int> mp;
        unordered_map<int,int> mp1;
        for(int i = 0;i<pre.size();i++){
            mp[pre[i]] = i;
        }
        for(int i = 0;i<preMirror.size();i++){
            mp1[preMirror[i]] = i;
        }
        queue<int> q;
        q.push(pre[0]);
        Node* root = new Node(pre[0]);
        Node* ans = root;
        unordered_map<int,int> mp2;
        mp2[pre[0]]++;
        unordered_map<int,Node*> mp3;
        mp3[pre[0]] = root;
        while(!q.empty()){
           int a = q.front();
           q.pop();
           
           int b = mp[a];
           int c = mp1[a];
           root = mp3[a];
           if(b+1 < pre.size()){
               if(mp2.find(pre[b+1]) == mp.end()){
                   Node* newNode = new Node(pre[b+1]);
                   mp3[pre[b+1]] = newNode;
                   root->left = newNode;
                   mp2[pre[b+1]]++;
                   q.push(pre[b+1]);
               }
           }
           if(c+1 < preMirror.size()){
               if(mp2.find(preMirror[c+1]) == mp.end()){
                   Node* newNode = new Node(preMirror[c+1]);
                   mp3[preMirror[c+1]] = newNode;
                   root->right = newNode;
                   mp2[preMirror[c+1]]++;
                   q.push(preMirror[c+1]);
               }
           }
        }
        return ans;
    }
};