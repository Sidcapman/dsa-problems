#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
 

    int dp[1002][1002];
    int solve(int w,int wt[],int val[],int n,int i)
    {
        if(i>=n||w<=0){
            return 0;
        }
        if(dp[w][i]!=-1)return dp[w][i];
        if(wt[i]>w)
        {
            return dp[w][i] = solve(w,wt,val,n,i+1);
        }
          return dp[w][i] = max(val[i]+solve(w-wt[i],wt,val,n,i+1),solve(w,wt,val,n,i+1));
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       memset(dp,-1,sizeof dp);
       int va=solve(w,wt,val,n,0);
       return va;
    }
};



int main()
 {

    int t;
    cin>>t;
    while(t--)
    {

        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];

        for(int i=0;i<n;i++)
            cin>>val[i];
        

        for(int i=0;i<n;i++)
            cin>>wt[i];
            
        Solution ob;
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  
