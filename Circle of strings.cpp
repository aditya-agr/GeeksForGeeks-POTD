class Solution {
  public:
    int isCircle(vector<string> &arr) {
        // code here
        vector<int> idx(26);
        int len = arr.size();
        
        for(string s : arr){
            int n = s.size();
            idx[s[0]-'a']++;
            idx[s[n-1]-'a']--;
        }
        for(int i : idx)
            if(i)
                return 0;

        unordered_map<char, vector<int>> mp;
        for(int i=0; i<len; i++)
            mp[arr[i][0]].push_back(i);
            
        vector<int> vis(len);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int ans = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int x : mp[arr[node].back()]){
                if(!vis[x]){
                    ans ++;
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        return ans==len;
    }
};