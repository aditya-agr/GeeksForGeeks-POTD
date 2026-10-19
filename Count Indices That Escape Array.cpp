class Solution {
  public:
    int goodIndices(vector<int> &arr) {
        // code here
        int n= arr.size();
        vector<bool>visited(n,false);
        unordered_set<int>possibleIndices;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int cur = i;
                unordered_set<int>visitedInLoop;
                bool possible = false;
                while(true){
                    if(cur<0 or cur>=n){
                        possible = true;
                        break;
                    }
                    else if(visitedInLoop.find(cur)!= visitedInLoop.end() or arr[cur]==0 ){
                        possible = false;
                        break;
                    }
                    visitedInLoop.insert(cur);
                    cur += arr[cur];
                }
                for(auto it:visitedInLoop){
                    visited[it] = true;
                }
                if(possible){
                    for(auto it:visitedInLoop)possibleIndices.insert(it);
                }

            }
        }
        return possibleIndices.size();
    }
};