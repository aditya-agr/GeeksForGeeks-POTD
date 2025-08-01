class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int i=0, j=0;
        int res = 0;
        int n = arr.size();
        while(j<n){
            mp[arr[j]]++;
            while(mp.size()>k){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                i++;
            } 
            res += j-i+1;
            j++;
        }
        return res;
    }
};