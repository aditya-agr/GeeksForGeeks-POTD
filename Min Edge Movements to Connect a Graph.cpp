class DSU {
    vector<int> parent;
    vector<int> rank;
  public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++)
            parent[i] = i;
    }
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py)
            return;
        if(rank[px] > rank[py])
            parent[py] = px;
        else if(rank[px] < rank[py])
            parent[px] = py;
        else{
            rank[px]++;
            parent[py] = px;
        }
    }
    int count(int n){
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
            mp[find(i)]++;
        return mp.size();
    }
};

class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        int m = edges.size();
        if(m < n-1)
            return -1;
        DSU dsu(n);
        for(vector<int> &e : edges){
            int u = e[0];
            int v = e[1];
            dsu.Union(u, v);
        }
        
        return dsu.count(n)-1;
    }
};