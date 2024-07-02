class Solution {
  public:
    bool isPalin(string s){
        int n = s.size();
        for(int i=0; i<n/2; i++)
            if(s[i]!=s[n-i-1])
                return false;
        return true;
    }
    bool compute(Node* head) {
        // Your code goes here
        string s="";
        while(head){
            s += head->data;
            head = head->next;
        }
        return isPalin(s);
    }
};