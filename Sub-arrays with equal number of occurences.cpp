class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        int cnt=0;
        unordered_map<int, int> mp;
        mp[0]++;
        int n = arr.size();
        int cntx=0, cnty=0;
        for(int i=0; i<n; i++){
            cntx += (arr[i]==x);
            cnty += (arr[i]==y);
            int diff = cntx - cnty;
            if(mp.find(diff) != mp.end())
                cnt += mp[diff];
            mp[diff]++;
        }
        return cnt;
    }
};