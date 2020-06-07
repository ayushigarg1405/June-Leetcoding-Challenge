**Question**

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number 
of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

**Solution Approach**

Sort the vector in decreasing order of first value and if same first value, then increasing order of second value.
The, insert the vectors one by one to the result at vectors's second index position in result vector.

**Solution**

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        vector<vector<int>>result;
        sort(people.begin(),people.end(),[](const vector<int>& a,const vector<int>& b){
			     return (a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]));
             });
        for(vector<int>& x: people) result.insert(result.begin() + x[1], x);
        return result;
    }
};
