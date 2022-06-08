#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dp[1001][801];
    int nCr(int n, int r){
        if(r>n)return dp[n][r]=0;
        if(n==r)return dp[n][r]=1;
        if(r==0)return dp[n][r]=1;
        if(r==1)return dp[n][r]=n;
        if(dp[n][r])return dp[n][r];
        return dp[n][r]=(nCr(n-1,r)+nCr(n-1,r-1))%1000000007;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  