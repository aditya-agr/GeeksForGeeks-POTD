struct Comp{
    bool operator()(const pair<int,int> &a, const pair<int, int> &b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};
class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp;
        set<pair<int,int>, Comp> st;
        
        int n = arr.size();
        for(int i=0; i<k; i++){
            mp[arr[i]]++;
        }
        for(auto it : mp)
            st.insert({it.second, it.first});
        
        
        int sum = (*st.begin()).second;
        for(int i=k; i<n; i++){
            st.erase({mp[arr[i]], arr[i]});
            mp[arr[i]]++;
            st.insert({mp[arr[i]], arr[i]});
            
            st.erase({mp[arr[i-k]], arr[i-k]});
            mp[arr[i-k]]--;
            st.insert({mp[arr[i-k]], arr[i-k]});
            
            sum += (*st.begin()).second;
        }
        return sum;
    }
};