/*----------Question-------------------

Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99

-----------Solution Approach:----------

Using hashmap to store count of each element

---------Solution---------
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> map;
        
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])!=map.end())
                map[nums[i]]++;
            else
                map[nums[i]]=1;
        }
        for(auto i : map){
            if(i.second!=3)
                return i.first;
        }
        return -1;
    }
};
