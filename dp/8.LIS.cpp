class Solution {
public:
    
    int solve(int now,vector<int>&nums,int prev,vector<int>& dp)
    {
        if(now==nums.size())return 0;
        if(dp[prev+1]!=-1)return dp[prev+1];
        int take=0,notake = solve(now+1,nums,prev,dp);
        if(prev==-1||nums[now]>nums[prev])take=1+solve(now+1,nums,now,dp);
        return dp[prev+1]=max(take,notake);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,-1,dp);
    }
    
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1);
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    } 
};

//link : https://leetcode.com/problems/longest-increasing-subsequence