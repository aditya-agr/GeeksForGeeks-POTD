class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        int len = 0;
        Node* curr = head;
        while(curr){
            curr = curr->next;
            len++;
        }
        int res=0, mid=-1, cnt=0;
        curr = head;
        while(curr){
            if(cnt == len/2)
                mid = curr->data;
            res = res^curr->data;
            curr = curr->next;
            cnt++;
        }
        if(len%2)
            return mid==res;
        return res==0;
    }
};