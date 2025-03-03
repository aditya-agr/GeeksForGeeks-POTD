class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        deque<int> mn, mx;
        vector<int> res;
        int n = arr.size();
        int j=0, ast=0, aed=0;
        for(int i=0; i<n; i++){
            
            while(!mx.empty() && arr[mx.back()]<arr[i])
                mx.pop_back();
            mx.push_back(i);
            
            while(!mn.empty() && arr[mn.back()]>arr[i])
                mn.pop_back();
            mn.push_back(i);
            
            while(arr[mx.front()]-arr[mn.front()]>x){
                if(j == mx.front())
                    mx.pop_front();
                if(j == mn.front())
                    mn.pop_front();
                j++;
            }
            if(i-j > aed-ast){
                ast = j;
                aed = i;
            }
        }
        for(int i=ast; i<=aed; i++)
            res.push_back(arr[i]);
        return res;
    }
};