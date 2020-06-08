**Question**

Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16

**Solution Approach**

Adding number to number-1 will lead to 0 -> it is power of 2

**Solution**

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
            return true;
        if(n==0)
            return false;
        return n>0 && ((n & (n-1))==0);
    }
};
