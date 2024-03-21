class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	queue<Node*> dq;
    	dq.push(root);
    	int flag=1;
    	while(!dq.empty()){
    	    int n = dq.size();
    	    vector<int> tmp(n);
    	    for(int i=0; i<n; i++){
    	        Node *curr = dq.front();
    	        dq.pop();
        	    if(flag) 
        	        tmp[i] = curr->data;
        	    else
        	        tmp[n-i-1] = curr->data;
        	    if(curr->left)
        	        dq.push(curr->left);
        	    if(curr->right)
        	        dq.push(curr->right);
    	    }
    	    flag = !flag;
    	    for(int i=0; i<n; i++){
    	        ans.push_back(tmp[i]);
    	    }
    	}
    	return ans;
    }
};