vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       int n = q.size();
       int flag=1;
       for(int i=0; i<n; i++){
           Node *node = q.front();
           q.pop();
           if(flag){
                res.push_back(node->data);
                flag=0;
           }
           if(node->left)
                q.push(node->left);
           if(node->right)
                q.push(node->right);
       }
   }
   return res;
}
