class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        sort(citations.rbegin(), citations.rend());
        int n = citations.size();
        int h = 0;
        for(int i=0; i<n; i++){
            if(citations[i] >= i+1)
                h = i+1;
        }
        return h;
    }
};