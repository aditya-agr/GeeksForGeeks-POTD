class Solution {
  public:
    void DFS(unordered_map<char, vector<char>> &adj, char u, stack<char> &st, unordered_set<char>&visited){
        visited.insert(u);
        for(char v : adj[u]){
            if(!visited.count(v))
                DFS(adj, v, st, visited);
        }
        st.push(u);
    }
    string findOrder(string dict[], int n, int k) {
        // code here
        unordered_map<char, vector<char>> adj;
        unordered_set<char> vertices;
        for(int i=1; i<n; i++){
            int x = dict[i-1].size();
            int y = dict[i].size();
            int j=0;
            while(j<x && j<y && dict[i][j]==dict[i-1][j])
                j++;
            if(j<x && j<y){
                adj[dict[i-1][j]].push_back(dict[i][j]);
                vertices.insert(dict[i-1][j]);
                vertices.insert(dict[i][j]);
            }
        }
        stack<char> st;
        unordered_set<char> visited;
        for(char u : vertices)
            if(!visited.count(u)) DFS(adj, u, st, visited);
        string res="";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};