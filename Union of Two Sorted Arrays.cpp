class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> res;
        int i=0, j=0;
        while(i<n && j<m){
            if(!res.empty() && arr1[i]==res.back()){
                i++;
                continue;
            }
            if(!res.empty() && arr2[j]==res.back()){
                j++;
                continue;
            }
            if(arr1[i]<arr2[j])
                res.push_back(arr1[i++]);
            else if(arr1[i]>arr2[j]) 
                res.push_back(arr2[j++]);
            else{
                res.push_back(arr1[i++]);
                j++;
            }
        }
        while(i<n){
            if(!res.empty() && arr1[i]==res.back()){
                i++;
                continue;
            }
            res.push_back(arr1[i++]);
        }
        while(j<m){
            if(!res.empty() && arr2[j]==res.back()){
                j++;
                continue;
            }
            res.push_back(arr2[j++]);
        }
        return res;
    }
};