class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        string temp = s1;
        int count = 1;
        while(temp.size() < s2.size()){
            temp += s1;
            count++;
        }
        if(temp.find(s2) != -1)
            return count;
        if((temp+s1).find(s2) != -1)
            return count+1;
        return -1;
    }
};