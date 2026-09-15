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
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 3){
            return max({nums[0] , nums[1] , nums[2]});
        }
        int n = nums.size();
        vector<int> dp1(n+1 , -1);
        vector<int> dp2(n+1 , -1);
        vector<int> dp3(n+1 , -1);
        vector<int> ans1;
        vector<int> ans2;
        vector<int> ans3;
        ans1 = nums;
        ans2 = nums;
        ans3 = nums;
        ans1.pop_back();
        ans2.erase(ans2.begin());
        ans3.erase(ans3.begin() + 1);
        return max({solve(ans1 , 0 , dp1) , solve(ans2 , 0 , dp2), solve(ans3 , 1 , dp3)});
    }
};
