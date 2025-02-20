class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> rightmin;
        priority_queue<int> leftmax;
        int n = arr.size();
        vector<double> res(n);
        for(int i=0; i<n; i++){
            leftmax.push(arr[i]);
            rightmin.push(leftmax.top());
            leftmax.pop();
            if(rightmin.size()>leftmax.size()){
                leftmax.push(rightmin.top());
                rightmin.pop();
            }
            if(rightmin.size()==leftmax.size())
                res[i] = (rightmin.top()+leftmax.top())/2.0;
            else
                res[i] = leftmax.top();
        }
        return res;
    }
};