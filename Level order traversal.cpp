class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      queue<Node*> q;
      vector<int> res;
      q.push(root);
      while(!q.empty()){
          Node*temp = q.front();
          q.pop();
          res.push_back(temp->data);
          if(temp->left) q.push(temp->left);
          if(temp->right) q.push(temp->right);
      }
      return res;
    }
};