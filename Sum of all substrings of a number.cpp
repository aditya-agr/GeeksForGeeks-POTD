class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        long long prev=0, curr=0, ans=0, m=1e9+7;
        int n = s.size();
        for(int i=0; i<n; i++){
            curr = ((prev*10)%m + (s[i]-'0')*(i+1)%m )%m;
            ans =(ans+curr)%m;
            prev = curr;
        }
        return ans;
        
    }
};