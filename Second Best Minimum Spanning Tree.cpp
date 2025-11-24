class DSU{
  public:
    vector<int> parent, sz;
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
            if(sz[px] > sz[py]){
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
    int secondMST(int V, vector<vector<int>> &edges) {
        // code here
        auto comp = [](vector<int> a, vector<int> b){
            return a[2] < b[2];
        };
        sort(edges.begin(), edges.end(), comp);
        int mst = 0, cnt = 0;
        int n = edges.size();
        DSU dsu(V);
        vector<int> sct;
        for(int i=0; i<n; i++){
            if(cnt == V-1)
                break;
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            int pu = dsu.find(u);
            int pv = dsu.find(v);
            if(pu == pv)
                continue;
            sct.push_back(i);
            dsu.Union(pu, pv);
            cnt++;
            mst += w;
        }
        if(cnt != V-1)
            return -1;
        int mn = INT_MAX;
        for(int j : sct){
            DSU dsu2(V);
            int cnt2 = 0, mst2 = 0;
            for(int i=0; i<n; i++){
                if(cnt2 == V-1)
                    break;
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                int pu = dsu2.find(u);
                int pv = dsu2.find(v);
                if(pu == pv || i==j)
                    continue;
                dsu2.Union(pu, pv);
                cnt2++;
                mst2 += w;
            }
            if(mst2 > mst && mst2 < mn && cnt2==V-1)
                mn = mst2;
        }
        return mn == INT_MAX ? -1 : mn;
    }
};