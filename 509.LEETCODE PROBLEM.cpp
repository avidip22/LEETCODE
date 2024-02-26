// leetcode problem number-509
// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

class Solution {
public:
    int fib(int n) {
        //base case 
        if(n==0)
        return 0;
        if(n==1)
        return 1;
        int ans = fib(n-1) + fib(n-2);
        return ans;
    }
};

// same problem using dp
// using Top down approach

#include<iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int> &dp){
    //base case 
    if(n <= 1)
    return n;
    if(dp[n] != -1)
    return dp[n];

    dp[n] =  fib(n-1, dp)+fib(n-2, dp);
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    // now make array of 1d for memoriazation
    
    vector<int>dp[n+1];
    for (int i = 0; i <=n; i++)
    dp[i]= -1;
    cout<<fib(n,dp)<<endl;
   
        
  
    
 return 0;
}

// same problem using Bottom-up approach

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    // step 1 make a 1d array
    vector<int>dp[n+1];
    // step-2 
    dp[0] = 0;
    dp[1] = 1;

    // step 3 
    for (int i = 2; i < n; i++)
    
        dp[i] = dp[i-1] + dp[i-2];
      cout<<dp[n]<<endl;
    
    
 return 0;
}
