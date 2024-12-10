class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0];
        int n = intervals.size(), count=0;
        for(int i=1; i<n; i++){
            if(prev[1] > intervals[i][0]){
                count++;
                prev[1] = min(prev[1], intervals[i][1]);
            }
            else
                prev = intervals[i];
        }
        return count;
    }
};