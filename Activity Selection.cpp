class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int, int>> idx;
        int n = start.size();
        for(int i=0; i<n; i++)
            idx.push_back({start[i], finish[i]});
        
        auto comp = [&](pair<int, int>&a, pair<int, int>&b){
            return a.second < b.second;
        };
        sort(idx.begin(), idx.end(), comp);
        int count = 1;
        int last = idx[0].second;
        for(int i=1; i<n; i++){
            if(idx[i].first > last){
                count++;
                last = idx[i].second;
            }
        }
        return count;
    }
};