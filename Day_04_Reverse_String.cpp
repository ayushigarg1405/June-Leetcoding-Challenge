**Question**

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 
Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

**Solution Approach**
1. Using reverse function.
2. Using temp variable to swap start and end values.

**Solution**

class Solution {
public:
    void reverseString(vector<char>& s) {
       /* int n = s.size();
        int start=0;
        int end=n-1;
        while(start<=end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
        */
        reverse(s.begin(),s.end());
    }
};
