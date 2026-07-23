class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& cost, int i) {
        if (i <= 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = min(
            solve(cost, i - 1) + cost[i - 1],
            solve(cost, i - 2) + cost[i - 2]
        );
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n + 1, -1);
        return solve(cost, n);
    }
};