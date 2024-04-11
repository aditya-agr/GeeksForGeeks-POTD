class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n){
        // Your code here
        vector<int> temp;
        while(n){
            if(n&1)temp.push_back(1);
            else temp.push_back(0);
            n>>=1;
        }
        reverse(temp.begin(),temp.end());
        for(int i=1;i<temp.size();i++){
            temp[i]=temp[i-1]^temp[i];
        }
        int ans=0,j=0;
        for(int i=temp.size()-1;i>=0;i--){
            if(temp[i])ans+=pow(2,j);
            j++;
        }
        return ans;
        
    }
};