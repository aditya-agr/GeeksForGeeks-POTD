class DSU{
public:
    vector<int> parent;
    vector<int> sz;
    DSU(int n){
        parent.resize(n);
        sz.resize(n, 1);
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
        if(px != py){
            if(sz[px] >= sz[py]){
                parent[py] = px;
                sz[px] += sz[py];
            }
            else{
                parent[px] = py;
                sz[py] += sz[px];
            }
        }
    }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        int n = stones.size();
        unordered_map<int, int> row, col;
        DSU dsu(n);
        for(int i=0; i<n; i++){
            int r = stones[i][0];
            int c = stones[i][1];
            if(row.count(r)){
                int x = row[r];
                x = dsu.find(x);
                dsu.Union(x, i);
            }
            else
                row[r] = i;
                
            if(col.count(c)){
                int x = col[c];
                x = dsu.find(x);
                dsu.Union(x, i);
            }
            else
                col[c] = i;
        }
        
        unordered_set<int> pnt;
        for(int i=0; i<n; i++)
            pnt.insert(dsu.find(i));
        
        int ans = 0;
        for(int x : pnt){
            ans += dsu.sz[x]-1;
        }
        return ans;
        
    }
};