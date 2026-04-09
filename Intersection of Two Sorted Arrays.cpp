class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> sol;
        int i = 0, j = 0;
        while(i<a.size() and j<b.size()){
            if(i>0 and a[i] == a[i-1]){
                // makes sure that we only match unique values only
                i++;continue;
            }
            if(a[i] < b[j]){
                i++;
            }
            else if(a[i] > b[j]){
                j++;
            }
            else{
                sol.push_back(a[i]);
                i++;j++;
            }
        }
        return sol;
    }
};