/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node *node = new Node(data);
        if(head->data >= data){
            node->next = head->next;
            head->next = node;
            swap(head->data, node->data);
            return head;
        }
        Node *temp = head;
        while(temp->next->data <= data && temp->next != head)
            temp = temp->next;
        node->next = temp->next;
        temp->next = node;
        return head;
    }
};