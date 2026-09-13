class Solution {
public:
    int characterReplacement(string s, int k) {
        int right = 0;
        int left = 0;
        int maxi = 0;
        int maxFreq = 0;
        unordered_map<char , int> mp;
        while(right < s.length()){
            mp[s[right]]++;
            for(const auto& pair : mp){
                if(pair.second > maxFreq){
                    maxFreq = pair.second;
                }
            }
            while((right-left+1) - maxFreq > k){
                    mp[s[left]]--;
                    left++;
                }
                maxi = max(maxi , right-left+1);
                right++;
        }
        return maxi;
    }
};
