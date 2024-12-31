class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> st;
        int res = 0;
        for(int x : arr){
            st.insert(x);
        }
        for(int x : arr){
            if(st.find(x-1) == st.end()){
                int cnt=0;
                while(st.count(x++))
                    cnt++;
                res = max(res, cnt);
            }
        }
        return res;
    }
};