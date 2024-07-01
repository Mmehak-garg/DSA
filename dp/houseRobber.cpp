#include <bits/stdc++.h> 
long long int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    long long int prev2 = 0, prev1 = nums[0];
    long long int curr = prev1;
    
    for (int i = 1; i < n; i++) {
        long long int pick = nums[i];
        if (i > 1) pick += prev2;
        long long int notPick = 0 + prev1;
        curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return curr;
 
}
long long int houseRobber(vector<int>& valueInHouse)
{
   vector<int> temp1,temp2;
   int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0];  // imp 
   for(int i =0;i<n;i++){
       if(i != n-1) temp1.push_back(valueInHouse[i]);
       if(i != 0) temp2.push_back(valueInHouse[i]);
   }
   return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
}