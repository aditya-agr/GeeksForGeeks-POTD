class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int, int> mp;
        int n = arr.size();
        int i=0, j=0;
        int res = 0;
        while(j<n){
            mp[arr[j]]++;
            while(mp.size() > 2){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};