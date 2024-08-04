class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code her
        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++)
            vec.push_back({end[i], start[i]});
        sort(vec.begin(), vec.end());
        int res=0, endt=-1;
        for(auto it : vec){
            if(it.second > endt){
                endt = it.first;
                res++;
            }
        }
        return res;
    }
};