class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        int n = preorder.size();
        vector<int> res;
        stack<int> st;
        for(int i=0; i<n; i++){
            int count = 0;
            int cur = preorder[i];
            while(!st.empty() && cur > st.top()){
                st.pop();
                count++;
            }
            if(count >= 2)
                res.push_back(preorder[i-1]);
            st.push(cur);
        }
        res.push_back(preorder[n-1]);
        return res;
    }
};