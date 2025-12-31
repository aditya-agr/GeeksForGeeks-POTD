/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:

    bool isPalindrome(Node *head) {
        // //  code here
        // vector<int> arr;
        // while(head){
        //     arr.push_back(head->data);
        //     head = head->next;
        // }
        // int n = arr.size();
        // for(int i=0; i<n/2; i++){
        //     if(arr[i] != arr[n-i-1])
        //         return false;
        // }
        // return true;
        
        Node* slow=head, *fast=head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *prev=NULL, *curr=slow->next, *nxt;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        slow->next = prev;
        slow = slow->next;
        while(slow){
            if(slow->data != head->data)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};