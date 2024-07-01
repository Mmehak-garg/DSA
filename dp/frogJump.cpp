// BY Recursion
int energy(int n, vector<int> &heights){
    if(n==0) return 0;
    int left = energy(n-1,heights) +abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n>1) right = energy(n-2,heights) +abs(heights[n]-heights[n-2]);

    return min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    return energy(n-1, heights);
   
}


// by  Memorization  tc -> O(N) SC -> O(N) +O(N)
int energy(int n, vector<int> &heights,vector<int> &dp){
    if(n==0) return 0;
    if(dp[n] != -1) return dp[n];
    int left = energy(n-1,heights,dp) +abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n>1) right = energy(n-2,heights,dp) +abs(heights[n]-heights[n-2]);

    return dp[n] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return energy(n-1, heights, dp);
   
}

// bottom up tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,0);
    dp[0] =0;
    for(int i =1;i<n;i++){
        int left = dp[i-1] +abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1) right= dp[i-2] +abs(heights[i]-heights[i-2]);
        dp[i] = min(left,right);
    }
    return dp[n-1];
   
}

// space optimaization when ever idx-1,idx-2 (100% of space optimization)
int frogJump(int n, vector<int> &heights)
{
    int prev2 = 0,prev1 = abs(heights[1]-heights[0]); 
    int curr =prev1;
    for(int i = 2;i<n;i++){
        int left =  prev1 +abs(heights[i]-heights[i-1]);
        int right= prev2 +abs(heights[i]-heights[i-2]);
        curr = min(left,right);
        prev2= prev1;
        prev1 = curr;
    }
    return curr;
   
}

// for kth step 
int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k) {
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];
    
    int mmSteps = INT_MAX;

    for (int j = 1; j <= k; j++) {
       if (ind - j >= 0) {
            int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            mmSteps = min(jump, mmSteps);
        }
    }
     return dp[ind] = mmSteps;
}