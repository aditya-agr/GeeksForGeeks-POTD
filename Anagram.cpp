class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        vector<int> idx(26);
        for(char c : s1)
            idx[c-'a']++;
        for(char c : s2)
            idx[c-'a']--;
        for(int i=0; i<26; i++)
            if(idx[i] != 0)
                return false;
        return true;
    }
};