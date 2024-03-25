class Solution{
public:	
    void helper(vector<string>&res, string s, int c0, int c1, int n){
        if(n==0){
            res.push_back(s);
            return;
        }
        helper(res, s+'1', c0, c1+1, n-1);
        if(c0<c1)
            helper(res, s+'0', c0+1, c1, n-1);
        return;
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> res;
	    helper(res, "", 0, 0, n);
	    return res;
	}
};