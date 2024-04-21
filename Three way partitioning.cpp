class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // code here 
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int curr = 0;
        
        while(curr<=end){
            
            if(arr[curr]<a)
            {
                swap(arr[start],arr[curr]);
                start++;
                curr++;
            }
            else if(arr[curr]>=a && arr[curr]<=b){
                curr++;
            }
            else
            {
                swap(arr[curr],arr[end]);
                end--;
            }
        }
        
    }
    
};