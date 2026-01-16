class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++){
            if(arr[i] != -1){
                int l = max(0, i-arr[i]);
                int r = min(n-1, i+arr[i]);
                vec.push_back({l, r});
            }
        }
        sort(vec.begin(), vec.end());
        int cnt = 0, cE = 0;
        int i=0, m=vec.size();
        while(cE < n){
            int mx = cE-1;
            while(i<m && vec[i].first <= cE){
                mx = max(mx, vec[i].second);
                i++;
            }
            if(mx < cE)
                return -1;
            cE = mx+1;
            cnt++;
        }
        return cnt;
    }
};