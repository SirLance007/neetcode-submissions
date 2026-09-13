class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxi = 0;
        unordered_map<char , int> mp;
        while(right < n){
            mp[s[right]]++;
            while(mp[s[right]] >= 2){
                mp[s[left]]--;
                left++;
            }
            maxi = max(maxi , right-left+1);
            right++;
        }
        return maxi;
    }
};
