class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> vec;
        vec.push_back(root->data);
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->left){
                vec.push_back(curr->left->data);
                q.push(curr->left);
            }
            else
                vec.push_back(0);
            if(curr->right){
                vec.push_back(curr->right->data);
                q.push(curr->right);
            }
            else
                vec.push_back(0);
        }
        return vec;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        // Your code here
        Node *root = new Node(arr[0]);
        int i = 1, n = arr.size();
        queue<Node*> q;
        q.push(root);
        while(i<n){
            Node* curr = q.front();
            q.pop();
            if(arr[i] != 0){
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;
            if(arr[i] != 0){
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};