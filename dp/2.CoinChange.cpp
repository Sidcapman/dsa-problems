// link : https://practice.geeksforgeeks.org/problems/coin-change2448/1# 

#include bitsstdc++.h
using namespace std;

class Solution {
  public
  long long dp[1001][1001];
  long long int solve(int s[],int m,int n,int i)
  {
      if(i==m)
     {
          if(n==0)return 1;
          else return 0;
     }
      if(dp[n][i]!=-1)return dp[n][i];
      if(s[i]n)return dp[n][i]=solve(s,m,n,i+1);
      else
      return dp[n][i]=solve(s,m,n-s[i],i)+solve(s,m,n,i+1);
  }
  
    long long int count(int s[], int m, int n) {
    memset(dp,-1,sizeof dp);
    sort(s,s+m);
    return solve(s,m,n,0);
       
    }
};


int main() {
    int t;
    cin  t;
    while (t--) {
        int n, m;
        cin  n  m;
        int arr[m];
        for (int i = 0; i  m; i++) cin  arr[i];
        Solution ob;
        cout  ob.count(arr, m, n)  endl;
    }

    return 0;
}   