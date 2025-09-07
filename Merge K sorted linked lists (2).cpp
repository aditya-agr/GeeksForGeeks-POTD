/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        Node *res = arr[0];
        int n = arr.size();
        for(int i=1; i<n; i++){
            Node *head = res;
            Node *curr = arr[i];
            Node *temp = new Node(0);
            res = temp;
            while(head && curr){
                if(head->data < curr->data){
                    temp->next = head;
                    head = head->next;
                }
                else{
                    temp->next = curr;
                    curr = curr->next;
                }
                temp = temp->next;
            }
            while(head){
                temp->next = head;
                head = head->next;
                temp = temp->next;
            }
            while(curr){
                temp->next = curr;
                curr = curr->next;
                temp = temp->next;
            }
            res = res->next;
        }
        return res;
    }
};