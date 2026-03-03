class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int, int> mp;
        int n = arr.size();
        int i=0, j=0;
        int res = 0, dist = 0;
        while(j<n){
            mp[arr[j]]++;
            if(mp[arr[j]] == 1)
                dist++;
            while(dist > 2){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0)
                    dist--;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};