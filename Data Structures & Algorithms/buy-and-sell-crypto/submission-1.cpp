class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int left = 0;
        int right = 1;
        while(right < prices.size()){
            if(prices[right] > prices[left]){
                maxi = max(maxi , prices[right] - prices[left]);
            }
            else{
                left = right;
            }
            right++;
        }
        return maxi;
    }
};
