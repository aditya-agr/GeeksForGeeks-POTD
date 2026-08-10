class Solution {
  public:
    vector<vector<int>>dp;
    int f(int i,int task,vector<int>&h,vector<int>&l){
        if(i==h.size())return 0;
        if(dp[i][task]!=-1)return dp[i][task];
        int op1=0+f(i+1,0,h,l);
        int op2=l[i]+f(i+1,1,h,l);
        int op3=0;
        if(i==0||!task)op3=h[i]+f(i+1,1,h,l);
        return dp[i][task]=max({op1,op2,op3});
    }
    
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n=h.size();
        dp=vector<vector<int>>(n,vector<int>(2,-1));
        return f(0,0,h,l);
    }
};