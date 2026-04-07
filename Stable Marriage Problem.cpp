class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        // code here
        int n = men.size();
        vector<vector<int>> rank(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                rank[i][women[i][j]] = j;
            }
        }
        vector<int> freeWomen(n, -1);
        vector<int> res(n, -1), nxt(n, 0);
        queue<int> q;
        for(int i=0; i<n; i++){
            q.push(i);
        }
        while(!q.empty()){
            int m = q.front();
            q.pop();
            int w = men[m][nxt[m]];
            nxt[m]++;
            
            if(freeWomen[w] == -1){
                freeWomen[w] = m;
                res[m] = w;
            }
            else{
                int cm = freeWomen[w];
                if(rank[w][m] < rank[w][cm]){
                    freeWomen[w] = m;
                    res[m] = w;
                    res[cm] = -1;
                    q.push(cm);
                }
                else
                    q.push(m);
            }
        }
        return res;
    }
};