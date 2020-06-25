/*
--------Question--------

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3

----------Solution Approach-----------
Method 1 - Using set to store values and return the value which repeats itself
Method 2 - Making use of slow and fast pointers. Finding the intersection point. 
           Start one pointer from 0 index and one from the intersection point, return the value at index where both pointers meet.
          
----------Solution---------

*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])!=s.end())
                return nums[i];
            else
                s.insert(nums[i]);
        }
        return -1;
    }
};
