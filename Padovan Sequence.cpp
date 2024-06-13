class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
       vector<int> p(4,1);
       int m=1e9+7;
       for(int i=3; i<=n; i++){
           p[3] = (p[0]+p[1])%m;
           p[0] = p[1];
           p[1] = p[2];
           p[2] = p[3];
       }
       return p[3];
    }
    
};
