**Question**

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

**Solution Approach**

Take three pointers - red,white and blue.
Initialize red as 0, white as 0 and blue as nums.size()-1
Now, swap values at red and white if 0 encounters , increment white when 1 encounters and swap values at white and blue if 2 encounters.

**Solution**

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int red = 0;
        int white = 0;
        int blue=n-1;
        
        while(white<=blue){
            switch(nums[white]){
                case 0:
                    swap(nums[red++],nums[white++]);
                    break;
                case 1:
                    white++;
                    break;
                case 2:
                    swap(nums[white],nums[blue--]);
                    break;
            }
        }
    }
};
