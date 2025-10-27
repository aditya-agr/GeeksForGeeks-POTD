class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        priority_queue<vector<int>> pq;
        int n = arr1.size();
        int m = arr2.size();
        
        for(int i=0; i<k && i<n; i++){
            for(int j=0; j<k && j<m; j++){
                if(pq.size() < k)
                    pq.push({arr1[i]+arr2[j], arr1[i], arr2[j]});
                else{
                    if(pq.top()[0] > arr1[i]+arr2[j]){
                        pq.pop();
                        pq.push({arr1[i]+arr2[j], arr1[i], arr2[j]});
                    }
                }
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            vector<int> tp = pq.top();
            pq.pop();
            res.push_back({tp[1], tp[2]});
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
