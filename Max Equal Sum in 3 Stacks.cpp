class Solution {
  public:
    int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        // code here
        int sum1=0;
        int n1 = s1.size();
        for(int i=0; i<n1; i++) 
            sum1 += s1[i];
        int sum2=0;
        int n2 = s2.size();
        for(int i=0; i<n2; i++) 
            sum2 += s2[i];
        int sum3=0;
        int n3 = s3.size();
        for(int i=0; i<n3; i++) 
            sum3 += s3[i];
        
        int i=0, j=0, k=0;
        while(sum1!=sum2 || sum1!=sum3){
            int mn = min(sum1, min(sum2, sum3));
            if(mn < sum1)
                sum1 -= s1[i++];
            if(mn < sum2)
                sum2 -= s2[j++];
            if(mn < sum3)
                sum3 -= s3[k++];
        }
        return sum1;
    }
};