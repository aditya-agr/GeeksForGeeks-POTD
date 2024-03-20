class Solution
{
public:
    
    void help(Node *root,int &ans,int &mxCount,int count,int sum){
        if(!root){
            if(count>mxCount){
                ans=sum;
                mxCount=count;
            }
            else if(count==mxCount){
                ans=max(ans,sum);
            }
            return;
        }
        sum+=root->data;
        count++;
        help(root->left,ans,mxCount,count,sum);
        help(root->right,ans,mxCount,count,sum);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int ans = INT_MIN,mxCount=0,count=0,sum=0;
        help(root,ans,mxCount,count,sum);
        return ans;
    }
};