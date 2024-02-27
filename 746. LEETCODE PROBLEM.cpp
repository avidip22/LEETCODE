// 746. Min Cost Climbing Stairs IN LEETCODE

class Solution {
public:
int solve(vector<int>& cost, int n, vector<int>& dp){
    //base case 
    if(n==0)
    return cost[0];
    if(n==1)
    return cost[1];

    // step-3
    if(dp[n]!= -1)
    return dp[n];
    
    // step 2
    dp[n] = cost[n] + min (solve(cost,n-1,dp),solve(cost,n-2,dp));
    return dp[n];

}
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // int ans = min(solve(cost,n-1), solve(cost,n-2));
        // return ans;
       // step 1 make dp array and initialize with -1
        int n = cost.size();
        vector<int>dp(n+1,-1);
        int ans = min(solve(cost,n-1,dp), solve(cost,n-2,dp));
        return ans;
         
    }
};
