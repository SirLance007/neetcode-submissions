class Solution {
private:
    int solve(string &s , int idx1 , int idx2 , vector<vector<int>> &dp){
        if(idx1 > idx2){
            return 0;
        }
        if(idx1 == idx2){
            return 1;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        if(s[idx1] == s[idx2]){
            return dp[idx1][idx2] = 2 + solve(s , idx1+1 , idx2-1 , dp);
        }else{
            return dp[idx1][idx2] = max(solve(s , idx1 , idx2-1 , dp) , solve(s , idx1+1 , idx2 , dp));
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1 , vector<int> (n+1 , -1));
        int ans = 0;
        string op = "";
        
        for(int i = 0; i < n; i++){
            // FIX 1: Run j down to 'i' instead of 0 to prevent negative substring lengths
            for(int j = n-1 ; j >= i ; j--){
                
                // FIX 2: Pruning. If the remaining length is smaller than our best answer, skip it
                if(j - i + 1 <= ans) {
                    break;
                }
                
                // FIX 3: Removed the 'cout' statements to prevent Time Limit Exceeded
                if(solve(s , i , j , dp) == j-i+1){
                    ans = j-i+1;
                    op = s.substr(i , j-i+1);
                    break; // FIX 4: Since we are checking from largest to smallest, the first match is the longest for this 'i'
                }
            }
        }
        return op;
    }
};