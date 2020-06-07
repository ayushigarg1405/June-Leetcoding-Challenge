**Question**

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. 
You may assume that you have infinite number of each kind of coin.


Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

**Solution Approach**

Dynamic Programming

**Solution**

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=coins[i-1];j<=amount;j++){
                dp[j]+=dp[j-coins[i-1]];
            }
        }
        return dp[amount];
    }
};
