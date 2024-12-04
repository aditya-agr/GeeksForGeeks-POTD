class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        string str = s1+s1;
        if(str.find(s2) == -1)
            return false;
        return true;
    }
};