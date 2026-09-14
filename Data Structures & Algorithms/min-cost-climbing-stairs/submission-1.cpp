class Solution {
private:
    int solve(vector<int> &cost , int idx , vector<int> &dp){
        if(idx >= cost.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        // one move 
        int one = cost[idx] + solve(cost , idx+1 , dp);
        // two move
        int two = cost[idx] + solve(cost , idx+2 , dp);

        dp[idx] = min(one , two);
        return dp[idx];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // states changing -> total cost , index
        vector<int> dp(n+1 , -1);
        int ans1 = solve(cost , 0 , dp);
        int ans2 = solve(cost , 1 , dp);
        return min(ans1 , ans2);
        // return ans;
    }
};
