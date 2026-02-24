class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        unordered_map<int, int> mp;
        int n = a1.size();
        int sum = 0, res = 0;
        mp[0] = -1;
        for(int i=0; i<n; i++){
            sum += a1[i];
            sum -= a2[i];
            if(!mp.count(sum))
                mp[sum] = i;
            else
                res = max(res, i-mp[sum]);
        }
        return res;
    }
};