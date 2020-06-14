**Question**

There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. 
If there is no such route, output -1.

**Solution**

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& cost, int src, int dst, int k, int& mini, int dist) {
        if(k < 0) {
            return;
        }
        if(src == dst) {
            mini = min(mini, dist);
            return;
        }
        for(auto i: graph[src]) {
            if(dist + cost[src][i] < mini) {  // Pruning step
                dfs(graph, cost, i, dst, k-1, mini, dist+cost[src][i]);   
            }
        }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> graph(n), cost(n, vector<int>(n));
        for(auto i: flights) {
            graph[i[0]].push_back(i[1]);
            cost[i[0]][i[1]] = i[2];
        }
        int mini = INT_MAX;
        dfs(graph, cost, src, dst, K+1, mini, 0);
        return mini == INT_MAX ? -1 : mini;
    }
};
