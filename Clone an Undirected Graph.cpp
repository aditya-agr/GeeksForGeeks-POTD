class Solution {
  public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        // code here
        if(mp.find(node) != mp.end())
            return mp[node];
        Node *clone1 = new Node(node->val);
        mp[node] = clone1;
        for(Node* it : node->neighbors)
            clone1->neighbors.push_back(cloneGraph(it));
        return clone1;
    }
};