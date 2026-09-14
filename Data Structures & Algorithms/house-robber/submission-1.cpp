class Solution {
private:
    int solve(vector<int> &nums , int idx , vector<int> &dp){
        if(idx >= nums.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int two = nums[idx] + solve(nums , idx+2 , dp);
        int three = nums[idx] + solve(nums , idx+3 , dp);
        dp[idx] = max(two , three);
        return dp[idx];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1 , -1);
        int ans1 = solve(nums , 0 , dp);
        int ans2 = solve(nums , 1 , dp);
        return max(ans1 , ans2);
    }
};
