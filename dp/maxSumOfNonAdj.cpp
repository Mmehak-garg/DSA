#include <bits/stdc++.h> 
int solve(int n,vector<int> &nums,vector<int> &dp){
  // baase case
  if(n==0) return nums[0];
  if(n<0) return 0;
  if(dp[n] != -1) return dp[n];
  int pick = nums[n]+solve(n-2,nums,dp);
  int notPick = solve(n-1,nums,dp);
  return dp[n] = max(pick,notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
  int n = nums.size();
  vector<int> dp(n,-1);
  return solve(n-1,nums,dp);
  
}

// tabulazation
int maximumNonAdjacentSum(vector<int> &nums){
  int n = nums.size();
  vector<int> dp(n,-1);
  dp[0] = nums[0];
  for(int i =1;i<n;i++){
    int pick = nums[i];
      if(i>1)
      pick = nums[i]+dp[i-2];
     int notPick = dp[i-1];
     dp[i] = max(pick,notPick);
  }
  return dp[n-1];
  // return solve(n-1,nums,dp);

  
}
// space otimization
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
  int n = nums.size();
 int prev2 = 0 , prev1 = nums[0];
 int curr = prev1;
  for(int i =1;i<n;i++){
    int pick = nums[i];
    if(i>1) pick += prev2;
    int notPick = 0+prev1;
    curr = max(pick,notPick);
    prev2 = prev1;
    prev1 = curr;
  }
  return curr;
 
}