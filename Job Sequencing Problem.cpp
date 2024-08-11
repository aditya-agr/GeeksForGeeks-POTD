class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        auto comp = [&](Job a, Job b){
            return a.profit>b.profit;
        };
        sort(arr, arr+n, comp);
        
        vector<int> idx(n+1);
        int num=0, profit=0;
        for(int i=0; i<n; i++){
            for(int j=arr[i].dead; j>0; j--){
                if(!idx[j]){
                    idx[j]=1;
                    num++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {num, profit};
    } 
};