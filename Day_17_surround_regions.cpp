**Question**

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

**Solution Approach**

Using DFS to mark 'O' which are connected to border 'O's 

**Solution**

vector<vector<char>> ans;
int n,m;

void abc(int i,int j) 
{
    ans[i][j]='p'; 
    if(i-1>=0 && ans[i-1][j]=='O')
        abc(i-1,j);
    if(i+1<n && ans[i+1][j]=='O')
        abc(i+1,j);
    if(j-1>=0 && ans[i][j-1]=='O')
        abc(i,j-1);
    if(j+1<m && ans[i][j+1]=='O')
        abc(i,j+1);
    return ;
}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        ans=board;
        int i,j,k;
        n=ans.size();
        if(n==0)
            return ;
        m=ans[0].size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i==n-1 || j==m-1 || i==0 || j==0)
                {   if(ans[i][j]=='O')
                    abc(i,j);
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(ans[i][j]=='p')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
    }
};
