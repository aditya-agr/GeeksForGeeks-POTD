class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // // Code here
        // vector<int> vec;
        // while(head1){
        //     vec.push_back(head1->data);
        //     head1 = head1->next;
        // }
        // while(head2){
        //     vec2.push_back(head2->data);
        //     head2 = head2->next;
        // }
        // sort(vec.begin(), vec.end());
        // sort(vec2.begin(), vec2.end());
        // int n = vec.size();
        // int m = vec2.size();
        // int i = 0, j = m-1;
        // int cnt=0;
        // while(i<n && j>=0){
        //     if(vec[i]+vec2[j]==x){
        //         cnt++;
        //         i++;
        //         j--;
        //     }
        //     else if(vec[i]+vec2[j]<x)
        //         i++;
        //     else
        //         j--;
        // }
        // return cnt;
        
        unordered_map<int, int> mp;
        while(head1){
            mp[head1->data]++;
            head1 = head1->next;
        }
        int cnt=0;
        while(head2){
            if(mp.find(x-head2->data) != mp.end())
                cnt++;
            head2 = head2->next;
        }
        return cnt;
    }
};