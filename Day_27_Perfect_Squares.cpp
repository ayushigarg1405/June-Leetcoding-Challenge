/*
-----------Question------------

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

-----------Solution Approach-----------

Similar to coins change problem using Dynamic Programming


---------Solution--------

*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i=1;i*i<=n;i++)
            squares.push_back(i*i);
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<squares.size();j++){
                if(squares[j]<=i){
                    int res = dp[i-squares[j]];
                    if(res!=INT_MAX and dp[i]>res+1)
                        dp[i]=res+1;
                }
            }
        }
        return dp[n];
    }
};
