/*------Question-----

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. 
Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or 
contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

-------Solution Approach -----

Using Dynamic Programming ( top down approach )


-------Solution-----

*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return 0;  // invalid
        int rows = dungeon.size(), cols = dungeon[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for (int i=rows-1; i >= 0; --i) {
            for (int j=cols-1; j >= 0; --j) {
                if (i == rows - 1 && j == cols - 1) {
                    dp[i][j] = min(0, dungeon[i][j]);
                }
                else if (i == rows - 1) {
                    dp[i][j] = min(0, dungeon[i][j] + dp[i][j+1]);
                }
                else if (j == cols - 1) {
                    dp[i][j] = min(0, dungeon[i][j] + dp[i+1][j]);
                }
                else {
                    dp[i][j] = min(0, dungeon[i][j] + max(dp[i][j+1], dp[i+1][j]));
                }
            }
        }
        return -dp[0][0] + 1;
    }
};
