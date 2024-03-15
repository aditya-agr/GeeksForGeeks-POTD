class Solution
{
    public:
    // your task is to complete this function
    Node* reverse(Node *root){
        Node*prev=NULL, *curr=root, *nxt = root->next;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    void sort(Node **head)
    {
        // Code here
        Node *new1, *new2, *root, *root2, *tem;
        tem = *head;
        root = new1 = tem;
        root2 = new2 = tem->next;
        tem = tem->next->next;
        int flag=1;
        while(tem){
            if(flag){
                new1->next = tem;
                new1 = new1->next;
            }
            else{
                new2->next = tem;
                new2 = new2->next;
            }
            flag = !flag;
            tem = tem->next;
        }
        new2->next = NULL;
        new1->next = NULL;
        root2 = reverse(root2);
        
        Node *rt, *res = new Node(0);
        rt = res;
        while(root && root2){
            if(root->data <= root2->data){
                res->next = root;
                root = root->next;
            }
            else{
                res->next = root2;
                root2 = root2->next;
            }
            res = res->next;
        }
        while(root){
            res->next = root;
            root = root->next;
            res = res->next;
        }
        while(root2){
            res->next = root2;
            root2 = root2->next;
            res = res->next;
        }
        *head = rt->next;
        
    }
};