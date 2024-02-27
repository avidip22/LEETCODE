// 746. Min Cost Climbing Stairs IN LEETCODE

// FIRST APPROACH IN DP IS TOP DOWN APPROACH 

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
// NOW SECOND APPROACH BOTTOM-UP
// THIS IS TAULATION APPROACH
class Solution
{
public:
    int solve(vector<int> &cost, int n)
    {
        // step 1 creation of dp array
        vector<int> dp(n + 1);
        // step 2 base case analysis
        dp[0] = cost[0];
        dp[1] = cost[1];
        // step 3
        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {

        int n = cost.size(0);
        return solve(cost,n);
    }
};
// 3RD APPROACH - SPACE OPTIMIZATION 
class Solution
{
public:
    int solve(vector<int> &cost, int n)
    {
        /
        // step 2 base case analysis
       int prev2 = cost[0];
        int prev2 = cost[1];
        // step 3
        for (int i = 2; i < n; i++)
        {
            int current = cost[i] + min(prev1,prev2);
            prev2 = prev1;
            prev1 = current; 
        }
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {

        int n = cost.size(0);
        return solve(cost,n);
    }
};





















