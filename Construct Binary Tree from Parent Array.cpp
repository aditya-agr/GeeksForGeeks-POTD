
class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        // Your code here
        unordered_map<int, Node*> mp;
        int n = parent.size();
        
        Node *head;
        
        for(int i=0; i<n; i++){
            if(mp.find(i) == mp.end())
                mp[i] = new Node(i);
            
            if(parent[i] != -1 && mp.find(parent[i]) == mp.end())
                mp[parent[i]] = new Node(parent[i]);
                
            if(parent[i]==-1)
                head = mp[i];
            else{
                if(mp[parent[i]]->left)
                    mp[parent[i]]->right = mp[i];
                else
                    mp[parent[i]]->left = mp[i];
            }
        }
        return head;
    }
};