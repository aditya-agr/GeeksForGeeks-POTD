class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        Node *curr = head;
	int len=0;
	while(curr){
		curr = curr->next;
		len++;
	}
	curr = head;
	int k = len/2;
	while(k--)
		curr = curr->next;
	return curr->data;
    }
};