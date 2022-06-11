#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
        //  int dp[101][100001];
// above line causes a seg fault try to do in vectors
    int solve(int i,vector<int>&arr,int sum,vector<vector<int>>&dp)
    {    if(sum>1e5 || i>arr.size() ) return 0;
         if(sum==0)return 1;
        if(i>=arr.size()){
            return 0;
            
        }
        
        if(dp[i][sum]!=-1)return dp[i][sum];
        if(arr[i]>sum)return dp[i][sum]=solve(i+1,arr,sum,dp);
    
        return dp[i][sum]=solve(i+1,arr,sum-arr[i],dp)+solve(i+1,arr,sum,dp)>0?1:0;
        
    }
    bool isSubsetSum(vector<int>arr, int sum){

        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
      if(solve(0,arr,sum,dp))return true;
      return false;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 