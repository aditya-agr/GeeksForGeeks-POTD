class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        vector<pair<int, pair<int,int>>> task;
        for(int i=0; i<n; i++)
            task.push_back({abs(a[i]-b[i]), {a[i], b[i]}});
        sort(task.rbegin(), task.rend());
        int res = 0;
        for(int i=0; i<n; i++){
            int d = task[i].first;
            int ap = task[i].second.first;
            int bp = task[i].second.second;
            if(ap>bp){
                if(x){
                    res += ap;
                    x--;
                }
                else{
                    res += bp;
                    y--;
                }
            }
            else if(bp>ap){
                if(y){
                    res += bp;
                    y--;
                }
                else{
                    res += ap;
                    x--;
                }    
            }
            else{
                res += ap;
            }
        }
        return res;
    }
};