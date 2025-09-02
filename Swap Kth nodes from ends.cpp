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
    Node* swapKth(Node* head, int k) {
        // code here
        Node *temp = head;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }
        Node *first, *second;
        if(k > n)
            return head;
        temp = head;
        for(int i=1; i<=n; i++){
            if(i == k)
                first = temp;
            if(i == n-k+1)
                second = temp;
            temp = temp->next;
        }
        int tem = first->data;
        first->data = second->data;
        second->data = tem;
        return head;
    }
};